首先我们需要对box进行排序，排序的目的 需要从小箱子到大箱子
目的是要保证当前的箱子 一定要是 后面的箱子才能放在它下面。

这样自然而然 动态转移方程就出来了
dp[i] 表示 以第i个箱子为底的 最大可堆的高度。
每当遍历到一个箱子，就去这个箱子前面找能放在它上面的箱子j，dp[i] = max(dp[i], dp[j]+ box[i][2]);

```
class Solution {
	int dp[3005];
public:
	int pileBox(vector<vector<int>>& box) {
		int n = box.size();
		memset(dp, 0, sizeof(dp));
		
		sort(box.begin(), box.end(), [](vector<int> box1, vector<int> box2) {
			int sum1 = box1[0] + box1[1] + box1[2];
			int sum2 = box2[0] + box2[1] + box2[2];
			if (sum1 != sum2) {
				return sum1 < sum2;
			}
			else return box1[2] < box2[2];
		});
		dp[0] = box[0][2];
        int res = dp[0];
		for (int i = 1; i < n; i++) {
			dp[i] = box[i][2];//不管怎么样，自己总是能放的
			for (int j = i - 1; j >= 0; j--) {
				if (box[i][0] > box[j][0] && box[i][1] > box[j][1] && box[i][2] > box[j][2]) {
					dp[i] = max(dp[i], dp[j] + box[i][2]);		
				}
			}
			res = max(dp[i], res);
		}
		return res;
	}
};
```
