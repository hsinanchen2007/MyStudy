### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let  max=0;//最大利润
    prices.reduce((m,v,i)=>{
        console.log(m);

        max = max > (v-m)? max : v-m;

        return m<v?m:v;

    },prices[0])
    return max;
};
```