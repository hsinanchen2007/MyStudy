### 解题思路
参考这位大佬的题解 https://leetcode-cn.com/problems/minimum-distance-to-type-a-word-using-two-fingers/solution/qing-xi-tu-jie-qiao-miao-de-dong-tai-gui-hua-by-hl/

先对二维字母表进行编号，转为1维数据。
dp[i][l][r]，i代表现在输入的字母index是i，l代表左手现在按的字母序号，j代表右手现在按的字母序号。
状态转移:
```
dp[i][l][r] = min(dp[i][l][r], dp[i-1][pre][r] + getDistance(pre, l));
dp[i][l][r] = min(dp[i][l][r], dp[i-1][l][pre] + getDistance(pre, r));
```

发现每次遍历只和第一次的有关，所以可以压缩掉i这一个维度，用i%2和(i-1)%2来做滚动数组。
状态转移:
```
dp[i%2][l][r] = min(dp[i%2][l][r], dp[(i-1)%2][pre][r] + getDistance(pre, l));
dp[i%2][l][r] = min(dp[i%2][l][r], dp[(i-1)%2][l][pre] + getDistance(pre, r));
```
再进行优化，你发现每次按下的时候，要么左手的字母和i的相同，要么右手的字母和i的相同。所以可以再压缩一次，用i代表一个手指的指向字母index
第一种状态转移，第一根手指移动，第二根手指不动：
```
dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j] + getDistance(pre, cur));
```
第二种状态转移，第一根手指不动，第二根手指移动，但是这里留意一点，因为第一根手指不动，所以移动后，仍然需要有一个手指是指向前一个位置的。因为两根手指是等价的，dp[l][r] == dp[r][l]，
```
dp[i%2][pre] = min(dp[i%2][pre], dp[(i-1)%2][j] + getDistance(j, cur));
```

### 代码

```cpp
class Solution {
public:
    int getDistance(int i, int j) {
        int x1 = i/6, x2 = j/6;
        int y1 = i%6, y2 = j%6;
        return abs(x2-x1) + abs(y2-y1);
    }

    int minimumDistance(string word) {
        vector<vector<int>> dp = vector<vector<int>>(2, vector<int>(26, 0));
        
        for (int i=0; i<26; i++) {
            dp[1][i] = INT_MAX;
        }
        int res = INT_MAX;
        for (int i=1; i<word.size(); i++) {
            int cur = word[i] - 'A';
            int pre = word[i-1] - 'A';
            for (int j=0; j<26; j++) {
                if (dp[(i-1)%2][j] == INT_MAX) {
                    continue;
                }
                dp[i%2][j] = min(dp[i%2][j], dp[(i-1)%2][j] + getDistance(pre, cur));
                dp[i%2][pre] = min(dp[i%2][pre], dp[(i-1)%2][j] + getDistance(j, cur));
                if (i == word.length()-1) {
                    res = min(res, min(dp[i%2][j], dp[i%2][pre]));
                }
            }
            dp[(i-1)%2] = vector<int>(26, INT_MAX); // 这里需要初始化刚刚用完的前一次的数组，因为下一轮的循环，它是需要求解的。
        }
        return res;
    }
};
```