/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    var profit =0 ;
    var min =prices[0];
   for(var i =1;i<prices.length;i++){
       if(prices[i]>prices[i-1]){
           profit=Math.max(profit,prices[i]-min);
       }else{
           min =Math.min(min,prices[i])
       }
   }
    return profit;
};