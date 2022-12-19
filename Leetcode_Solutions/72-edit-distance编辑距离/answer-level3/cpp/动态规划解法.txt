### 解题思路
动态规划的最优化原理：
把多阶段过程转化为一系列单阶段问题，利用各阶段之间的关系，逐个求解。

在这个问题中，我们可以定义数组二维数组dp，其中的dp[i][j]表示：
将word1的前i个字符组成的单词，转化成word2的前j个字符组成的单词所需要的步数。

根据这个定义我们将原来的问题转化成了填写dp数组的问题。从定义出发，我们可以明显的得出，dp[0][j] = j,dp[i][0] = i;
而当word1[i] == word2[j]时dp[i][j] = dp[i-1][j-1];
当  word2[i] != word2[j]时dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1;
其中dp[i-1][j-1]表示替换操作(即要将word1[0:i]转化为word2[0:j]需要在将word1[0:i-1]转化word2[0:j-1]的基础之上将word1[i]替换为word2[j]);
其中dp[i-1][j]表示删除操作(即要将word1[0:i]转化为word2[0:j]需要在将word1[0:i-1]转化word2[0:j]的基础之上将word1[i]删除);
其中dp[i][j-1]表示插入操作(即要将word1[0:i]转化为word2[0:j]需要在将word1[0:i]转化word2[0:j-1]的基础之上在word1[i-1]后面插入字符word1[i]);

将该想法翻译成代码如下：

### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1    = word1.size();
        int n2    = word2.size();
        int min1  = 0,min2 = 0;
        int ** dp = new int*[n1+1];
        for(int i = 0; i < n1+1; i++){
            dp[i] = new int [n2+1]();
        }
        for(int r = 0; r < n1+1; r++){
            for(int c =0; c < n2+1; c++){
                if(r == 0 && c != 0){
                    dp[r][c] = c;
                }else if(r != 0 && c == 0){
                    dp[r][c] = r;
                }else if(r == 0 && c == 0){
                    dp[r][c] = 0;
                }else{
                    if(word1[r-1] == word2[c-1]){
                        dp[r][c] = dp[r-1][c-1];
                    }else{
                        min1 = (dp[r-1][c-1] >= dp[r][c-1])?dp[r][c-1]:dp[r-1][c-1];
                        min2 = (min1 >= dp[r-1][c])?dp[r-1][c]:min1;
                        dp[r][c] = min2 + 1;
                    }
                }

            }
        }
        /*for(int r = 0; r < n1+1; r++){
            for(int c = 0; c < n2+1; c++){
                cout << dp[r][c] << " ";
            }
            cout << endl;
        }*/
        return dp[n1][n2];
    }
};
```