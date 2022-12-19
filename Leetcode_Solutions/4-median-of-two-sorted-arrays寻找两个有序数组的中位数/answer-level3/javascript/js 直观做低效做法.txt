![image.png](https://pic.leetcode-cn.com/cd18b7e528bda90c4253d52ec5a7a74556caffed1183bfa4cece20040536e162-image.png)

### 解题思路
```js
直观思路：
合并数组，排序，找中位数
```

### 代码

```javascript
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */

var findMedianSortedArrays = function(nums1, nums2) {
  let nums = [...nums1, ...nums2], ans = null, n = nums.length;
  
  nums.sort((a, b) => a - b);
  
  let mid = (n - 1) >> 1;
  if (n % 2 === 0) {
    ans = (nums[mid] + nums[mid + 1]) / 2;
  } else {
    ans = nums[mid];
  }
  
  return ans;
};
```