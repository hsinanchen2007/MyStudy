![image.png](https://pic.leetcode-cn.com/2e6cdfd9ea8b42f963df51d09ee62c9720470a70696e58f2576b56b199edef2d-image.png)

### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @param {number} threshold
 * @return {number}
 */

/*
  滑动窗口
*/
var numOfSubarrays = function(arr, k, threshold) {
  if (arr.length < k) return 0;
  
  let ans = 0,
      len = arr.length,
      sum = 0,
      target = threshold === 0 ? 0 : k * threshold;
  
  for (let i = 0; i < k; i++) sum += arr[i];
  
  if (sum >= target) ans++;
  
  for (let i = k; i < len; i++) {
    sum -= arr[i - k];
    sum += arr[i];
    if (sum >= target) {
      ans++;
    }
  }
  
  return ans;
};
```