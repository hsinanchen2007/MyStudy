方法一： 双指针

```
var maxProfit = function(prices) {
    let count =0  // 最大值
    // 双指针 p, q
    let p = 0   
    let q = 1
    while(q < prices.length){
        // 后一个值减去前一个值小于0时都p =q q指针++
        if(prices[q] - prices[p]< 0 ){
             p = q
             q++
        } else{
            // 后一个值大于前一个值时算出此时可能存在的最大值
            if(count<(prices[q] - prices[p])){
                count = prices[q] - prices[p]
            }    
            q++ 
        }
    }
    return count
};
```
方法二 暴力解法 双层循环

```
var maxProfit = function(prices) {
        let res = 0
        for(let i=prices.length;i>0;i--){
            for(let j =0;j<i;j++){
               if(res<(prices[i]-prices[j])){
                  res = prices[i]-prices[j]
               }
                
            }
        }
        return res
};
```
