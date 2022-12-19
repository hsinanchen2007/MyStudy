和之前做过的一道很像[486. 预测赢家](https://leetcode-cn.com/problems/predict-the-winner/)

如果你能理解上一道题，那么这道题很容易想到用dp了

```c++
class Solution {
public:
	string stoneGameIII(vector<int>& stoneValue) {
		int len = stoneValue.size();


		//dp[i]表示的含义是：先手者从i开始拿，最多能从剩余数组中得到多少领先
		//初始化为0，，并且长度稍微大于len以便留一定的余量
		vector<int> dp(len + 1, 0);

		//根据题意，子问题都在当前问题的后面，要从后往前，确保之前的子问题已经求出解
		for (int i = len - 1; i >= 0; i--) {
			int mt = INT_MIN; //mt为从i开始取能获得的最大领先，初始化为负无穷
			int sum = 0;//取的累计和

			//尝试取1个，2个，3个 或者取到最末尾（j< len），然后求得不同取法的最大值，就是当前问题的解
			for (int j = i; j < i + 3 && j < len; j++) {
				sum += stoneValue[j]; //取的累计和
				int t = sum - dp[j + 1]; // 取完后，轮到对手取了，所以要减去对手能获得的最大分数，就是自己的得分
				mt = max(t, mt);
			}
			dp[i] = mt;

		}
		if (dp[0] > 0) return "Alice";
		else if (dp[0] < 0) return "Bob";
		else return "Tie";
	}
};
```
