分为两次暴力解法：

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
     let totalBiggest = 0;
    //暴力法1
//     for(let i = 0,len = prices.length;i<len;i++ ) {
//         let biggest = 0;
//         let curPrice = prices[i];
//         let restLargePrices = prices.slice(i+1).filter(p=>p>curPrice)
//         if(restLargePrices.length === 0) {
//             biggest = 0;
//         } else {
//             for(j=0,jlen = restLargePrices.length;j<jlen;j++) {
//                 let value = restLargePrices.map(price =>price- curPrice)
//                 biggest = Math.max(...value)
//             }
//             console.log(biggest)
//             totalBiggest = biggest>totalBiggest?biggest:totalBiggest
//         }
    
//     }
    // 暴力法2
    for(let n = 0,len=prices.length;n<len-1;n++) {
        for(let m = n+ 1;m<len;m++) {
            let current = prices[m] - prices[n];
            
                totalBiggest = current >totalBiggest?current:totalBiggest
            
        }
    }
    return totalBiggest;

};
```
一次遍历。
```javascript
    // 贪心算法
     let totalBiggest = 0;
     let low = Number.MAX_SAFE_INTEGER;
    for(let i = 0,len=prices.length;i<len;i++) {
        low = prices[i] < low ? prices[i]:low;
        if(prices[i] < low) {
            low = prices[i]
        } else {
            totalBiggest = prices[i] - low > totalBiggest ? prices[i]- low:totalBiggest
        }
        
    }
    return totalBiggest;

```
