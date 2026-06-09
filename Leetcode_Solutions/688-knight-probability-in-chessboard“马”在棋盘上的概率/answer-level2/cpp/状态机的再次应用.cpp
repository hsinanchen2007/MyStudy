### 解题思路
【先赞后看，养成习惯】
本题的思路很直观，基本上将`状态转移方程`写出来之后，就可以直接写出代码啦~
### 状态定义
`dp[i][j][k]`：表示从`(i,j)`走`k`步，“马”仍然在棋盘上的概率，我们如果**逆向思考**，从最终达到的目的地往回“跳”，那么`dp[i][j][k]`也表示从棋盘其他位置，走`k`步，到`(i,j)`的概率。
### 状态转移
从上文逆向思考后的`状态定义`，我们考虑第`k`步，到达`(i,j)`的可能位置有
| 可能位置 |  第几步|
|-|-
| `(i - 2,   j - 1)` | k - 1 |
| `(i - 2,   j + 1)` | k - 1 |
| `(i - 1,   j - 2)` | k - 1 |
| `(i - 1,   j + 2)` | k - 1 |
| `(i + 1,   j - 2)` | k - 1 |
| `(i + 1,   j + 2)` | k - 1 |
| `(i + 2,   j - 1)` | k - 1 |
| `(i + 2,   j + 1)` | k - 1 |

因此我们可以建立`状态转移方程`
$$
dp[i][j][k]=
\begin{cases}
dp[i-2][j-1][k-1]+dp[i-2][j+1][k-1]+\\
dp[i-1][j-2][k-1]+dp[i-1][j+2][k-1]+\\
dp[i+1][j-2][k-1]+dp[i+1][j+2][k-1]+\\
dp[i+2][j-1][k-1]+dp[i+2][j+1][k-1]
\end{cases}
$$

### 动画展示

<![批注 2020-02-07 155918.png](https://pic.leetcode-cn.com/de615f5f90c7d5aab15176e6c7cdac4f256427a6c99e4499925fda22816a7563-%E6%89%B9%E6%B3%A8%202020-02-07%20155918.png),![批注 2020-02-07 155933.png](https://pic.leetcode-cn.com/8e0512e85440ca31c115afe142f2ca51921869030d881fea3ac7db6788839e1f-%E6%89%B9%E6%B3%A8%202020-02-07%20155933.png),![批注 2020-02-07 155945.png](https://pic.leetcode-cn.com/7dce91e29dad76ec674d6dee09bfb367fea47cb622697b0cf93d4dfc82c97ae7-%E6%89%B9%E6%B3%A8%202020-02-07%20155945.png)>





### 相关题目
[LeetCode935 骑士拨号器](https://leetcode-cn.com/problems/knight-dialer/)

### 我的题解
[LeetCode1262 可被三整除的最大和](https://leetcode-cn.com/problems/greatest-sum-divisible-by-three/solution/dong-tai-gui-hua-yu-zhuang-tai-zhuan-yi-by-christm/)
### 代码

```cpp
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if (N == 0) { return 0; }
	vector<vector<vector<double>>> dp(N + 4, vector<vector<double>>(N + 4, vector<double>(K + 1)));
	for (int i = 0; i < N + 4; i++) {
		for (int j = 0; j < N + 4; j++) {
			if ((i) >= 2 && (i) <= N + 1) {
				if ((j)>= 2 && (j) <= N + 1) {
					dp[i][j][0] = 1;
				}
			}
			else {
				dp[i][j][0] = 0;
			}
		}
	}
	for (int k = 1; k <= K; k++) {
		for (int i = 2; i <= N + 1; i++) {
			for (int j = 2; j <= N + 1; j++) {
				dp[i][j][k] = (dp[i - 2][j - 1][k - 1] + dp[i - 2][j + 1][k - 1] + \
							   dp[i - 1][j - 2][k - 1] + dp[i - 1][j + 2][k - 1] + \
					           dp[i + 1][j - 2][k - 1] + dp[i + 1][j + 2][k - 1] + \
					           dp[i + 2][j - 1][k - 1] + dp[i + 2][j + 1][k - 1]) / 8.0;
			}
		}
	}
	
	return dp[r + 2][c + 2][K];
    }
};
```

