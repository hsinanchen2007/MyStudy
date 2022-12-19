```
/**
 * @param {number[]} price
 * @param {number[][]} special
 * @param {number[]} needs
 * @return {number}
 */

var shoppingOffers = function(price, special, needs) {
    return shopping(price, special, needs);
};

function shopping (price = [], special = [], needs = []) {
    let res = calculatePriceIndividually(needs, price);

    // 购买礼包比购买单品划算，回溯的选择条件就是：礼包中的物品数量 不超过 需求中对应的物品数量，就选择礼包
    for (let i = 0; i < special.length; i++) {
        const remainingNeeds = []; 
        const currentSpecial = special[i];
        let j = 0;
        for (; j < needs.length; j++) {
            const diff = needs[j] - currentSpecial[j];
            // 不选择礼包的条件是：礼包中的物品数量 大于 需求中对应的物品数量
            if (diff < 0) {
                break;
            } 
        
            remainingNeeds[j] = diff;
        }
        
        // 当前礼包中的物品 全都小于或等于 需求中对应的物品，就选择购买礼包
        if (j === needs.length) {
            res = Math.min(res, currentSpecial[j]+ shopping(price, special, remainingNeeds))
        }
    }

    return res;
}

function calculatePriceIndividually (needs = [], prices = []) {
    let price = 0;
    for (let i = 0; i < needs.length; i++) {
        price += needs[i] * prices[i];
    }
    return price;
}
```