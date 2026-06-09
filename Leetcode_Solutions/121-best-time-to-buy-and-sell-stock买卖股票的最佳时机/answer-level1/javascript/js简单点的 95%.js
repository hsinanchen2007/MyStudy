`/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let max = 0
    let tempMax = 0
    for (let i = 0; i < prices.length; i++) {
        for (let j = i + 1; j < prices.length; j++) {
            if (prices[j] > prices[i]) {
                tempMax = prices[j] - prices[i]
                if (max < tempMax) {
                    max = tempMax
                }
            }
        }
    }
    return max
}`