### 解题思路
//这题贪心的方法会陷入局部最优，贪心就是每一层可走的方向走值最小的那个数
//一开始就限定了范围，有可能最优解就在那个不能到达的范围内

//dp问题

//从上往下会有特判，有的点只有一个方向可以走
//从上往下就是当前层的元素由上一层的哪些元素可以到达，有的可以是两个，有的在边边上的只能有1个，需要特判

//从下往上每个点都有两个方向
//当前层由下一层哪些元素可以到达，每个元素都有两个，正下方以及正下方右边那一个

//需要压缩空间，保证在O(n)内
//dp[i]表示当前遍历层到达第i个元素的最小路径之和
![image.png](https://pic.leetcode-cn.com/bd376e84096b009b7da96e4da1b88a14e8de5b6912fb79e02aab5c47f451bd9e-image.png)

### 代码

```cpp
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
		if(!n)
			return 0;
		vector<int> dp(n,0);
		//用三角形最下面一层初始化一下dp，因为最下面一层的dp值就是本身
		for(int i=0;i<n;i++)
			dp[i]=triangle[n-1][i];
		for(int i=n-2;i>=0;i--)
			for(int j=0;j<=i;j++)//第i层就有i个元素
				dp[j]=min(dp[j],dp[j+1])+triangle[i][j];
				//正下方和正下方右边之间的最小值加上本位置的值
		return dp[0];
    }
};
```