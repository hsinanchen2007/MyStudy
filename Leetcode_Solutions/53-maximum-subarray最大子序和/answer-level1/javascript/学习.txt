## 第一版，强行暴力解，迭代所有子数组（从长度为`1`的子数组开始到长度为`nums.length`的子数组）并分别计算其和，返回最大值。果然在意料之内的超时了。
> 超时
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let max = nums[0];
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > max) max = nums[i];
  }
  if (max < 0) return max;
  for (let i = 2; i <= nums.length; i++) {
    for (let j = 0; j <= nums.length - i; j++) {
      let cur = nums[j];
      for (let k = 1; k < i; k++) {
        cur += nums[j + k];
      }
      // console.log(i, j, nums[j], nums.slice(j,j+i), cur,max); // nums.slice(j,j+i)即当前正在计算的子数组和
      if (cur > max) max = cur;
    }
  }
  return max;
};
```

## 第二版，仍然暴力解，迭代所有子数组（从以 `nums[0]` 开头的子数组到以 `nums[nums.length-1]` 开头的子数组）并分别计算其和，返回最大值。这回没超时。
> 264ms,35M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let max = nums[0];
  for (let i = 0; i < nums.length; i++) {
    let cur = 0;
    for (let j = i; j < nums.length; j++) {
      // console.log(i,nums[i], j,nums[j],nums.slice(i,j))
      cur += nums[j];
      if (cur > max) max = cur;
    }
  }
  return max;
};
```

## 第三版，动态规划，参见 [题解](https://leetcode-cn.com/problems/maximum-subarray/solution/hua-jie-suan-fa-53-zui-da-zi-xu-he-by-guanpengchn)
> 72ms,35.1M。
```javascript []
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
  let maxSum = nums[0];
  let tempSum = nums[0];
  for (let i = 1; i < nums.length; i++) {
    tempSum = tempSum > 0 ? tempSum + nums[i] : nums[i];
    if (tempSum > maxSum) maxSum = tempSum;
  }
  return maxSum;
};
```
### 记录一下自己的思路历程
- `如果 sum > 0，则说明 sum 对结果有增益效果，则 sum 保留并加上当前遍历数字`，`如果 sum <= 0，则说明 sum 对结果无增益效果，需要舍弃，则 sum 直接更新为当前遍历数字`
- 在写暴力法之前就已经考虑到是不是可以通过判断后一个值 `nums[i]` 是否可以带来增益来决定是否对sum值做增改。
- 不过由于这个方向错误，使用 `nums[i]` 的情况下绞尽脑汁也没有得出方便可行的流程，而且也完全没有往使用 `tempSum` 来判断增益这个方面思考。所以只好想办法先暴力解，然后再去看题解学习。
- 正确的判断应是之前已经计算得到的 `tempSum` 是否带来增益来决定是否保留它

## to do 学习使用分治方法解