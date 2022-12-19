## 第一版，二分查找
> 148ms,37.4M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  nums = nums.sort((a, b) => a - b);
  if (nums[0] !== 0) return 0;
  let len = nums.length >> 1;
  let missingNum = len;
  while (1) {
    len >>= 1;
    if (nums[missingNum] === missingNum) missingNum += (len || 1);
    else if (missingNum - 1 === nums[missingNum - 1]) return missingNum;
    else missingNum -= (len || 1);
  }
};
```
## 看这效率显然还有更好的方法，接下来看了 [官方题解](https://leetcode-cn.com/problems/missing-number/solution/que-shi-shu-zi-by-leetcode/)，真的感觉自己的思维还不够用。
---
## 第二版，数学方法
> 84ms,36.5M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  let sum = 0;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
  }
  return (0 + nums.length) * (nums.length + 1) / 2 - sum;
};
```
## 高斯公式计算出未缺失数字情况下的和然后减去参数数组所有项的和，结果就是缺失的数字
---
## 第三版，异或运算
> 92ms,36.5M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  let res = 0;
  for (let i = 0; i < nums.length + 1; i++) {
    res ^= i ^ (nums[i] || 0);
  }
  return res;
};
```
## 如果未缺失数字的话，数组所有下标的值异或上所有项的值结果应该是0。但是缺失了一个数字的话那么所有下标和所有值异或的结果将会是缺失的那个数