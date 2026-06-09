回文是我的弱点，实在是想不出来，看各位大佬的题解了

首先这题可以先做一下131题，那个是这题的基础。
下面的解法的思路是：
1、如果字符串长度为1，那么不切割次数为0；长度为1的时候，最多切割次数1次，因为可以切割成2个长度为1的字串。所以长度为j的字符串，它对应的最多的切割次数就是j-1次。所以我们定义一个数组min_cut，min_cut[j]表示以0~j的字符串的最小切割次数。初始化min_cut[j]=j;
2、先处理一下[0~j]的字串，选择其中的i引索，0<=i<=j. 如果[i~j]是回文串，那么就可以在i-1和i之间切割一次，这样的话，min_cut[j]就是[0~i-1]的最小切割次数+1，或者说是现在的min_cut[j].二者之间取最小值，所以有 min_cut[j] = min(min_cut[j], 1 + min_cut[i-1]); 另外有个特殊点，就是i==0的时候，这个时候就已经是[0~j]的字符串了，所以也不需要切割，min_cut=0。 这里我们需要去从0到j遍历i，来求得min_cut[j]
3、需要从0到s.length-1去遍历j.得到最后的答案。
4、上面需要判断[i~j]是不是回文串，这里就涉及到了一个回文串的判断问题，经典解法也是用dp。dp[i][j]代表[i~j]的字串是不是回文。如果s[i]==s[j]且
 (j - i < 2 || dp[j + 1][i - 1]).前面一个代表[i+1~j-1]字串长度小于2，后面那个代表掐头去尾后的字串也是回文串。然后你会发现判断回文串的遍历过程和上面min_cut的遍历过程是一样的，所以可以将二者写在同一个循环里面。

```
class Solution {
public:
    int minCut(string s) {
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        vector<int> min_cut(s.length(), 0);
        for (int i=0; i<s.length(); i++) {
            min_cut[i] = i;
        }
        
        for (int j=0; j<s.length(); j++) {
            for (int i=0; i<=j; i++) {
                if (s[i] == s[j] && (j-i < 2 || dp[i+1][j-1])) {
                    dp[i][j] = true;
                    if (i == 0) {
                        min_cut[j] = 0;
                    } else {
                        min_cut[j] = min(min_cut[j], 1 + min_cut[i-1]);
                    }
                }
            }
        }
        return min_cut[s.length() - 1];
    }
};
```