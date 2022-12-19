### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function (candies, num_people) {
    let result = (new Array(num_people)).fill(0)
    let count = 0
    while (candies > 0) {
        result[count%num_people] += Math.min(++count, candies)
        candies -= count
    }
    return result
};
```