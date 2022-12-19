- nums中有n个奇数
- 编号为 1 2 3 ... n
- dp[i]代表第i个奇数在nums中的索引
- 则dp[0] 代表-1 因为-1刚好挨着0 相当于在nums前面插入一个奇数
- 任意连续k个奇数的数列有  例如包含编号2 知道编号为 k+1的数列的个数为
- (dp[2]-dp[1]) * (dp[k+2]-dp[k-1])
- 在nums后面在push一个1  则可以求出以nums中最后一个数列
```
var numberOfSubarrays = function(nums, k) {
  nums.push(1);
  let dp = [-1];
  let sum = 0;
  for (let i = 0, len = nums.length, start = 0; i < len; ++i) {
    if (nums[i] % 2) {
      dp.push(i);
      if (dp[k+1]) {
        sum += (dp[start+1]-dp[start]) * (dp[k+1]-dp[k])
        ++k;
        ++start;
      }
    }
  }
  return sum;
};
```
