#include "GildedRose.h"

const int MAX_QUALITY = 50;
const int BACKSTAGE_QUALITY_INCREMENT = 11;
const int BACKSTAGE_QUALITY_INCREMENT2 = 6;

const std::string SULFURAS = "Sulfuras, Hand of Ragnaros";
const std::string BACKSTAGE_PASS = "Backstage passes to a TAFKAL80ETC concert";
const std::string AGED_BRIE = "Aged Brie";

class GildedRoseItem {
    Item& item;

    bool isSulfuras() const {
        return item.name == SULFURAS;
    }

    bool isBackstagePass() const {
        return item.name == BACKSTAGE_PASS;
    }

    bool isAgedBrie() const {
        return item.name == AGED_BRIE;
    }

    bool isNormalItem() const {
        return !isAgedBrie() && !isBackstagePass();
    }

    void decreaseQuality() {
        if (item.quality > 0)
            item.quality -= 1;
    }

    void increaseQuality() {
        if (item.quality < MAX_QUALITY)
            item.quality += 1;
    }

    void handleBackstagePassQuality() {
        if (item.sellIn < BACKSTAGE_QUALITY_INCREMENT)
            increaseQuality();
        if (item.sellIn < BACKSTAGE_QUALITY_INCREMENT2)
            increaseQuality();
    }
    
public:
    explicit GildedRoseItem(Item& item) : item(item) {}

    void updateQuality() {
        if (!isSulfuras()) {
            if (isNormalItem())
                decreaseQuality();
            else {
                increaseQuality();
                if (isBackstagePass())
                    handleBackstagePassQuality();
            }

            item.sellIn--;

            if (item.sellIn < 0) {
                if (isNormalItem())
                    decreaseQuality();
                else if (isBackstagePass())
                    item.quality = 0;
                else if (isAgedBrie() && item.quality < MAX_QUALITY)
                    increaseQuality();
            }
        }
    }
};

GildedRose::GildedRose(std::vector<Item> const& items) : items(items) {}

GildedRose::GildedRose(std::vector<Item>&& items) : items(std::move(items)) {}

void GildedRose::updateQuality() {
    for (Item& item : items) {
        GildedRoseItem gildedRoseItem(item);
        gildedRoseItem.updateQuality();
    }
}
