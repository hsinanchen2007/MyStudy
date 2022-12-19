### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} candies
 * @return {number}
 */
 var distributeCandies = function(candies) {
  let half = candies.length / 2
  let singleLen = [...new Set(candies)].length
  if(half <= singleLen ) return half
  return singleLen
};
```