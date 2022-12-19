### 解题思路
参考官方，做如下记录:
#### 贪心算法
使用单个数组作为输入来查找最大（或最小）元素（或总和）的问题，贪心算法是可以在线性时间解决的方法之一。
每一步都选择最佳方案，到最后就是全局最优的方案。
#### 算法：
该算法通用且简单：遍历数组并在每个步骤中更新：

- 当前元素
- 当前元素位置的最大和
- 迄今为止的最大和

#### 复杂度分析

时间复杂度：O(N)。只遍历一次数组。
空间复杂度：O(1)，只使用了常数空间。

### 代码

```javascript
/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    if(nums.length === 1) return nums[0];
    if(nums.length === 0) return -Math.pow(2, 31);
    let len = nums.length;
    let currSum = nums[0];
    let maxSum = nums[0];
    for(let i=1;i<nums.length;i++) {
        currSum = Math.max(nums[i], currSum + nums[i]);
        maxSum = Math.max(maxSum, currSum);
    }
    return maxSum;
};
```