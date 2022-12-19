![image.png](https://pic.leetcode-cn.com/ea02205fb238d79e6d7dcdf227bb19a62e77ee3254455d03003f101bcff9317e-image.png)

### 解题思路
```js
直观思路：
给每个小朋友分糖果，一个一个分，直到把所有糖果分完
```

### 代码

```javascript
/**
 * @param {number} candies
 * @param {number} num_people
 * @return {number[]}
 */

var distributeCandies = function(candies, num_people) {
  let ans = new Array( num_people ).fill( 0 );
  
  let curr = 1, currIndex = 0;
  while (candies > 0) {
    if (candies <= curr) {
      ans[currIndex] += candies;
    } else {
      ans[currIndex] += curr;
    }
    
    candies -= curr;
    curr++;
    currIndex = currIndex === num_people - 1 ? 0 : currIndex + 1;
  }
  
  return ans;
};
```