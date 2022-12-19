### 解题思路
我的代码是否惊艳到了你？？？

### 代码

```javascript
/**
 * @param {number[]} candies
 * @return {number}
 */
var distributeCandies = function(candies) {
    const cat = new Set(candies).size
    return Math.min(cat, candies.length / 2)
};
```