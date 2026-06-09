### 解题思路
1. 创建长度为人数的数组，并且每一项都等于0
2. 循环，当前剩下的糖果大于0
3. 循环下标，或取当前的应该给的糖果数目

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
    let res = [...new Array(num_people).keys()];
    res = res.map((item, index) => item - index);
    let cur = 1;
    let index = 0;
    while(candies > 0) {
        // console.log(index, candies, cur);
        res[index] += cur;
        candies -= cur;
        if(candies >= cur + 1) {
            cur++;
        } else {
            cur = candies;
            break;
        }
        index = (index + 1) > (num_people - 1) ? 0 : (index + 1);
    }
    index = (index + 1) > (num_people - 1) ? 0 : (index + 1);
    res[index] += cur;
    return res;
};
```