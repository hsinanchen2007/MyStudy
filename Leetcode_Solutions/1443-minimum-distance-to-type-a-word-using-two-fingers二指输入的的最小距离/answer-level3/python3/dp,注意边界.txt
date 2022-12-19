### 解题思路
dp，三个变量，dp[i][j][k]分别表示现在的字母位置，左手字母位置，右手字母位置。然后递推公式就是可能的跳跃方式，取最小。不过在过程中要注意边界问题，每个手指从没有到有时不需要花费距离的。
### 代码

```python3
class Solution:
    def minimumDistance(self, word: str) -> int:
        # print('B' - 'A')
        def get_axis(s):
            ss = ord(s) - ord('A')
            x = int(ss/6)
            y = ss%6
            return x, y
        
        # print(get_axis('Z'))
        dp = []
        for i in range(len(word)+1):
            tmp = []
            for j in range(len(word)+1):
                tmpp = [1e5]*(len(word)+1)
                tmp.append(tmpp)
            dp.append(tmp)
        # print(dp)
        dp[0][0][0] = 0
        dp[1][1][0] = 0
        dp[1][0][1] = 0
        dp[2][1][2] = 0
        dp[2][2][1] = 0
        for i in range(1, len(word)+1):
            for j in range(i-1):
                # for k in range(i):
                tmp_now = get_axis(word[i-2])
                tmp_nex = get_axis(word[i-1])
                dis = abs(tmp_nex[0] - tmp_now[0]) + abs(tmp_nex[1] - tmp_now[1])
                dp[i][i][j] = min(dp[i][i][j], dp[i-1][i-1][j] + dis)
                dp[i][j][i] = min(dp[i][j][i], dp[i-1][j][i-1] + dis)
            for k in range(i-1):
                tmp_now = get_axis(word[k-1])
                tmp_nex = get_axis(word[i-1])
                dis = abs(tmp_nex[0] - tmp_now[0]) + abs(tmp_nex[1] - tmp_now[1])
                if k == 0:
                    dis = 0
                dp[i][i][i-1] = min(dp[i][i][i-1], dp[i-1][k][i-1] + dis)
                dp[i][i-1][i] = min(dp[i][i-1][i], dp[i-1][i-1][k] + dis)

        re = 1e5
        l = len(word)
        # print(dp)
        for i in range(len(word)):
            re = min(re, dp[l][l][i])
            re = min(re, dp[l][i][l])
        return re

```