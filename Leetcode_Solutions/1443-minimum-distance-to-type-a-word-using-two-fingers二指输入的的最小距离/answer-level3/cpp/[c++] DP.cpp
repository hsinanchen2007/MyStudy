**最简单的方法 :**
由于左手指必定取第一个,遍历右手指所有情况,计算总路径,由此可直接写出暴力DFS.  
每个字母不是左手指就是右手指,所以复杂度为O(2^n),显然超出时间限制

**动态规划 :**
左手指从left移动到curCharInd花费的路径
`DP[cur][curCharInd][right] = min(DP[cur - 1][left][right] +getDis(left, curCharInd),DP[cur][curCharInd][right]);`
右手指从right移动到curCharInd花费的路径
`DP[cur][left][curCharInd] = min(DP[cur - 1][left][right] +getDis(right, curCharInd),DP[cur][left][curCharInd]);`
左右手指分别移动的最小情况
`res = min(  min(DP[cur][curCharInd][right], DP[cur][left][curCharInd])  ,res);`

代码:
```
class Solution {
public:
    int minimumDistance(string word) {

        /**
         * DP[i][l][r] 代表以第i个字母结尾,左手恰好在l位置,右手恰好在r位置时最少的步数
         * 为了方便表示未开始时,手指放置的位置以及对应的路径,设置 i = i + 1
         * 初始化DP数组,DP第0行为未开始时左右手的位置,路径为0
         */
        vector<vector<vector<int> > > DP(word.size() + 1, vector<vector<int> >(26, vector<int>(26, 0)));
        for (int i = 1; i <= word.size(); i++) {
            for (int l = 0; l < 26; l++) {
                for (int r = 0; r < 26; r++) {
                    DP[i][l][r] = INT_MAX;
                }
            }
        }

        int res = INT_MAX;
        for (int cur = 1; cur <= word.size(); cur++) {
            // 当前字母
            int curCharInd = word[cur - 1] - 'A';
            // 遍历每一种左右手指所对应的字母情况
            for (int left = 0; left < 26; left++) {
                for (int right = 0; right < 26; right++) {

                    if (DP[cur - 1][left][right] != INT_MAX) { // 存在上一种情况
                        // 左手指从left移动到curCharInd花费的路径
                        DP[cur][curCharInd][right] = min(DP[cur][curCharInd][right],
                                                         DP[cur - 1][left][right] +getDis(left, curCharInd));

                        // 右手指从right移动到curCharInd花费的路径
                        DP[cur][left][curCharInd] = min(DP[cur][left][curCharInd],
                                                        DP[cur - 1][left][right] +getDis(right, curCharInd));
                    }

                    if (cur == word.size()) {
                        res = min(res,
                                min(DP[cur][curCharInd][right], DP[cur][left][curCharInd])
                                // 左右手指分别移动的最小情况
                        );
                    }
                }
            }
        }
        return res;
    }

    int getDis(int A, int B) {
        int xa = A % 6, ya = A / 6;
        int xb = B % 6, yb = B / 6;
        return abs(xa - xb) + abs(ya - yb);
    }
};
```
