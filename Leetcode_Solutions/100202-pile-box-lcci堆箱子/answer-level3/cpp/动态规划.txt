这题描述属实有毛病。
给👴看晕了。好好的说长宽高我不就看懂了吗。而且前面宽 wi、高hi、深di，后面数据又换位置[wi, di, hi]。

思路：
由于下面的三围要比上面的大，那么我们先对其中一围降序排序。那么现在可以确定的是，题目的答案一定是排序后的序列的子序列。
那么很显然，这个时候就可以动态规划了，。
转移方程
```
if (box[i][0] < box[j][0] && box[i][1] < box[j][1] && box[i][2] < box[j][2]){                   
					dp[i] = max(dp[i], dp[j] + box[i][2]);
}
```


`
class Solution {
public:
	static bool cmp(vector<int>&a, vector<int>&b) {
       return a[0] > b[0];
      
	}
	int dp[3003];
	int pileBox(vector<vector<int>>& box) {
		
		sort(box.begin(), box.end(),cmp);
		int ans = 0;
		for (int i = 0; i < box.size(); i++) {
			dp[i] = box[i][2];
			for (int j = 0; j < i; j++) {
				if (box[i][0] < box[j][0] && box[i][1] < box[j][1] && box[i][2] < box[j][2])                {                   
                
					dp[i] = max(dp[i], dp[j] + box[i][2]);
				}
			}
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};
`