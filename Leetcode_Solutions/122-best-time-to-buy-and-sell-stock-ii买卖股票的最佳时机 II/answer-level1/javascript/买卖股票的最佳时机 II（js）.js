# 萌新一枚，望各路大神多多指正
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    /*
        当前点之前上升，且当前点大于下一点，则当期点为峰值
        当前点之前下降，且当前点小于下一点，则当期点为谷值
        只需要将所有临近的峰值和谷值相减，并叠加，就可以得到最大利润了
        要注意的是：当最后一点为峰值是要做特殊处理
    */
    var l=0, // 当前谷值
        flag=false, // 表明此前股票趋势是逞上升（true）还是下降（false）趋势
        profit=0, 
        len=prices.length;
    for(let i=0; i<len-1; i++){
        if(prices[i] <= prices[i+1] && !flag){ // 更新谷值
            l=i;
            flag=!flag;
        }
        if(prices[i] <= prices[i+1] && i===len-2){ // 最后一点为峰值
            profit += prices[i+1] - prices[l];
        }
        if(prices[i] > prices[i+1] && flag){ // 当前峰值
            profit += prices[i] - prices[l]; // 峰值和临近谷值相加
            flag=!flag;
        }
    }
    return profit > 0 ? profit : 0;
}