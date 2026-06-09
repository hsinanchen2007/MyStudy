### 解题思路
参考官方题解的做法

思路：
dp[i][j]表示s[i...] 和 p[j...] 是否匹配。
假如s[i]==p[j]，或者p[j]=='.', 那么s[i]和p[j]是匹配的。我们需要继续看后面的是否匹配。
那么反过来。如果我们已经知道了后面的是否匹配。我们就可以推出dp[i][j]的状态了。所以使用从底向上的dp方法。
如果p的下一个字母是不是'*'，这个时候分两种情况。
如果p[j+1]=='*'。那么我们可以忽略掉p[j, j+1]，意味着*取0个；或者说当第一个字母匹配的时候，可以继续匹配s[i+1]和p[j].
如果不是'*'，那么如果第一个字母匹配，我们可以继续匹配s[i+1]和p[j+1]

初始化条件，认为 dp[s.size()][p.size()] = true; 因为两个都是越界，所以匹配。
但是循环的遍历条件也很迷糊，s的需要从size开始，而p的则需要从size-1开始。从数据上看，如果p也从size开始，则会将初始化条件也覆盖为false，最后全都是false。
如果s也从size-1开始，那么初始化条件也没用到。
### 代码

```cpp
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp = vector<vector<bool>>(s.size() + 1, vector<bool>(p.size()+1, false));
        dp[s.size()][p.size()] = true;
        for (int i=(int)s.size(); i>=0; i--) {
            for (int j = (int)p.size()-1; j>=0; j--) {
                bool firstMatch = i < (int)s.size() && (s[i] == p[j] || p[j] == '.');
                if (j + 1 < p.size() && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (firstMatch && dp[i+1][j]);
                } else {
                    dp[i][j] = firstMatch && dp[i+1][j+1];
                }
            }
        }
        return dp[0][0];
    }
};
```