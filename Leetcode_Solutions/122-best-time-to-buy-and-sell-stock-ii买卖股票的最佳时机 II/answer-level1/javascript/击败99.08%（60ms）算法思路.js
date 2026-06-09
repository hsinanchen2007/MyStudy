**思路**
首先是**买入时机**，只要第二天比第一天价格底且没有持股，就可以买入。然后在第二天卖出
**卖出时机**分2种情况
    如果第二天不会降价，且卖出有收益 即可卖出
    如果是最后一天，只要有收益即可卖出

代码如下：
```
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    const length = prices.length
    // 总利润
    let t = 0
    // 当前持有的价格
    let h = undefined
    for(let i=0;i<length;i++){
        const today = prices[i]
        const today1 = prices[i+1]
        // 买入
        if(h === undefined && today < today1){
            h = today
            continue
        }
        // 正常交易日卖出
        if(today>today1 && h < today && h !== undefined){
            t=today - h + t
            h = undefined
            continue
        }
        // 最后交易日卖出
        if(today1 === undefined && h < today && h !==undefined){
             t=today - h +t
            h = undefined
        }
    
    }
    return t
};
```
