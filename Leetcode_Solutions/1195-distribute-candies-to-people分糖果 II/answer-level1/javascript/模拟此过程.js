### 解题思路

模拟过程比较简单，具体看代码

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */
var distributeCandies = function(candies, num_people) {
  const ans = new Array(num_people).fill(0)
  let candieCounter = 1
  while (candies > 0) {
    for (let i = 0; i < num_people && candies > 0; i++) {
      if (candies > candieCounter) {
        ans[i] += candieCounter
        candies -= candieCounter
        candieCounter++
      } else {
        ans[i] += candies
        candies = 0
      }
    }
  }
  return ans
};
```