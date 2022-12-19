### 解题思路
 动态规划，根据题目给的三种操作。因为对word1的删除其实就是对于word2的插入，同理，对于word1的插入就是对于word2的删除。而对于替换来说，替换word1和word2其实是同一种意思。
 因此，我定义一个r[i][j],代表着word1的前i个变为word2的前j个的最小操作数。而对于之前说的，就变为了三种状态，r[i - 1][j - 1],r[i][j - 1],r[i - 1][j]。
 所以，对于当前的r[i][j]来说，如果当前对应的word1[i] == word2[j]的，就只需要是前一个的状态，r[i - 1][j - 1]就可以了。而不相等来说，就是需要进行操作了，至于是对word1的删除r[i - 1][j]，还是word2的删除r[i][j - 1]，还是对于word1的修改r[i - 1][j - 1]的即可。在此基础上加一即可。

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> r(n + 1 , vector<int>(m + 1 , 0));
        for(int i = 1 ; i <= n ; i++)r[i][0] = i;
        for(int i = 1 ; i <= m ; i++)r[0][i] = i;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1 ; j <= m ; j++){
                if(word1[i - 1] == word2[j - 1])r[i][j] = r[i - 1][j - 1];
                else r[i][j] = min(r[i - 1][j - 1] , min(r[i][j - 1] , r[i - 1][j]) )+ 1;
            }
        }
        return r[n][m];
    }
};
```