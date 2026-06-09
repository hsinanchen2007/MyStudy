### 首先明确这个问题是否可以使用动态规划去解决
对于这个问题而言，原问题是能否跳到最后一个位置。对问题的不同解释就导致了解决问题时的不同方法，每个人对于相同问题的理解可能都是不同的。首先需要将这个问题完整的描述成最简单的形式。
我的理解是，从起点出发，到达最后一个位置时的剩余步数至少等于0时才可以认为此时可以跳到最后。那么这个问题是否可以划分成子问题呢？
答案是肯定的，如下：
- 1.从起点出发时 i = 0，nums[0]里的数显而易见的是剩余步数同时也是当前可走步数，那么对于下一个点i = 1而言，其剩余步数必然为nums[0] - 1， 当前可走步数是 nums[1];
- 2.为了保证尽可能的走更远的路，我们希望对每一个点而言其剩余步数越多越好。基于这样的假设，对于 i = 2 位置时，其剩余步数可能时 i = 1 的剩余步数 - 1，也可能是以 i = 1 为起点走到这里的剩余步数nums[1] - 1, 为了满足假设取二者最大值，也就是说我们的数据结构可以选取一个数组来存储每个点的最大剩余步数。
- 3.一旦在某个位置最大剩余步数小于0，就可以返回失败。
思考如何描述问题，比思考如何解决问题可能更加复杂。
基于这样的假设，可以实现为如下代码：
```
class Solution {
public:
	bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return true;
		vector<int> dp(nums.size());
        dp[0] = nums[0];
		for (int i = 1; i < n; i++)
		{
			dp[i] = max(dp[i - 1] - 1, nums[i - 1] - 1);
			if (dp[i] < 0) return false;
		}
		return true;
	}
};
```

注意到当前时刻的最大剩余步数，只与前一位置的最大剩余步数和前一位置的可走步数有关，因此时间上并不需要一整个数组，仅仅需要常数个空间就足够了，改进如下：
```
class Solution {
public:
	bool canJump(vector<int>& nums) {
        if (nums.empty()) return true;
		int prev = nums[0];
		for (int i = 1; i < nums.size(); i++)
		{
			int curr = max(prev - 1, nums[i - 1] - 1);
			if (curr < 0) return false;
			prev = curr;
		}
		return true;
	}
};
```


