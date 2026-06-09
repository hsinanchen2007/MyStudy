```
/**
 * @param {number[]} nums
 * @return {number[]}
 */
var largestDivisibleSubset = function(nums) {
    if (!nums.length) return [];
    nums.sort((a, b) => a - b);
    let dp = new Array(nums.length).fill(1);
	let pre = new Array(nums.length);
	for (let i = nums.length - 1; i >= 0; i--) {
		for (let j = i - 1; j >= 0; j--) {
			if (nums[i] % nums[j] === 0) {
				dp[j] = Math.max(dp[i]+1, dp[j]);
				pre[j] = dp[i]+1 >= dp[j] ? i : pre[j];
			}
		}
	}

	const biggest = dp.indexOf(dp.reduce((a, b) => Math.max(a, b)));
	const res = [nums[biggest]];
	let i = biggest;
	while (pre[i]) {
		res.push(nums[pre[i]]);
		i = pre[i];
	}
	return res;
};
```
