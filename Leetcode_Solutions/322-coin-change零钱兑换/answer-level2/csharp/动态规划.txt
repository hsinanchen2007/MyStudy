### 解题思路
最朴素、原始的方法，用数组记录。(既然是求最小值，那就让不可达的地方值较大即可，参考解题区大佬)
用空间换取时间
### 代码

```cpp
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int **a = new int*[coins.size()];
		for (int i = 0; i < coins.size(); i++) {
			a[i] = new int[amount + 1];
		}
		int Mymax = amount+1; // 初始化
		for (int j = 1; j <= amount; j++) {
			if (j % coins[0] == 0) {
				a[0][j] = j / coins[0];
			}
			else {
				a[0][j] = Mymax;
			}
		}
		for (int i = 0; i < coins.size(); i++) {
			a[i][0] = 0;
		}

		// 循环
		for (int i = 1; i < coins.size(); i++) {
			for (int j = 1; j <= amount; j++) {
				if (coins[i] <= j) {
					int m = a[i][j - coins[i]] + 1;
					int n = a[i-1][j];
					a[i][j] = (m>n)?n:m;
				}
				else {
					a[i][j] = a[i - 1][j];
				}
			}
		}
		int res = a[coins.size() - 1][amount];
		return (res > amount)?-1:res;
	}
};
```