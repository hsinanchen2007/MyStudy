先用普通方法，后面学会动态规划分治法再来补优化
执行用时 :
92 ms
, 在所有 JavaScript 提交中击败了
83.04%
的用户
内存消耗 :
34.9 MB
, 在所有 JavaScript 提交中击败了
70.00%
的用户

var maxSubArray = function(nums) {
  let result = nums[0];
    let sum = nums[0] >= 0 ? 0 :nums[0] ; //这里要判断的，有可能传入的数组全是负数，不能初始化为0
    for(let i = 0; i< nums.length; i++) {
        sum = nums[i] > sum+nums[i] ? nums[i] : sum+nums[i];
        result = sum > result ? sum : result;
    };
    return result;
};