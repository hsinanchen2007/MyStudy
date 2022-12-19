### 解题思路
dp[i]:nums[0...i-1]的累计和（包括这两个值）
初始值dp[0]=0;
状态转移
dp[i+1]=nums[i]+dp[i];
计算sumrange如下：
sumrange(i,j)=dp[j+1]-dp[i]

### 代码

```cpp
//dp[i]:nums[0...i-1]的累计和（包括这两个值）：
class NumArray {
public:
	vector<int> dp;
	NumArray(vector<int>& nums) {
		//初始值
		dp.assign(nums.size()+1, 0);
		//状态转移
		for (int i=0;i<nums.size();i++)
		{
			dp[i+1] = nums[i] + dp[i];
		}
	}
	int sumRange(int i, int j) {
		return dp[j + 1] - dp[i];
	}
};
```