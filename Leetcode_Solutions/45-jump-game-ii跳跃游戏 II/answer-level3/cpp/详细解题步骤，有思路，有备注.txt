### 解题思路
此处撰写解题思路
题目分析： 求到末尾的最小跳数，假设index=i能一步跳到末尾，我是不是要求跳到i的最小跳数。
开辟额外空间dp[nums.size()] 表示到达某个点用的最小跳数。
假设当前位置为i，j为i下一次跳的距离 此距离<=nums[i]
则递推公式为：dp[i+j]=min(dp[i+j],dp[i]+i) //由于dp[i+j]不一定是从i点跳过去的，还可能是从其他位置跳过去的，反正谁小我取谁
### 代码

```cpp
class Solution {
public:
    int jump(vector<int>& nums) {
		int len = nums.size();
		vector<int> dp;				//纪录到达某个点用的最小跳数。
		dp.resize(len, -1);			//由于取的是最小，不能初始化为0，所以我初始化为-1
		dp[0] = 0;					//从0跳到0用的步数是0
		for (int i = 0; i < len; i++)
		{
			for (int j = nums[i]; j > 0; j--)	//用++ 和--区别不太大
			{
				if (i +j >= len)	//可能数组越界
					continue;
				if (dp[i + j] == -1)//没去过
					dp[i + j] = dp[i] + 1;
				else
				{
					dp[i + j] = min(dp[i + j], dp[i] + 1);	//从当前点跳和从其他点跳做比较
				}
				if (i + j == len - 1)			//刚好跳到末尾
					return dp[i ]+1;
				if ( i + j+nums[i+j] >= len - 1)	//如果从i跳两步能到达末尾 则直接输出，剪枝
													//此步骤在逻辑上并不重要，但是在这个题很重要
													//不加这一句会超时
					return dp[i] + 2;
				
			}
		}
		return dp[len - 1];
	}
};
```