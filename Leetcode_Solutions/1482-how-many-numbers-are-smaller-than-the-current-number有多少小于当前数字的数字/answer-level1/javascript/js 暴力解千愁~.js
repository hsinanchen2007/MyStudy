![image.png](https://pic.leetcode-cn.com/ccd59ed6dcdd27a45715fc2af30afb07bc551a7eabcba7e49e45c22189f3a734-image.png)

### 解题思路
```js
想了半天，建立索引数组啥的，调试了一会烦了，暴力解千愁
```

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number[]}
 */

var smallerNumbersThanCurrent = function(nums) {
  let ans = [], n = nums.length;
  
  for (let i = 0; i < n; i++) {
    let c = nums[i], count = 0;
    for (let j = 0; j < n; j++) {
      if (i !== j && nums[j] < c) {
        count++;
      }
    }
    ans.push( count );
  }
  
  return ans;
};
```