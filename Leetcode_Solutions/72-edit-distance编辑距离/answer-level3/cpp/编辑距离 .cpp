
解题思路
后一次的匹配基于前一次匹配成功的基础上，在这个条件上考虑当前匹配可能的3种情况

![编辑距离.jpg](https://pic.leetcode-cn.com/2af63cd010ba59a27a335cb942ae36ef28e3b0b69f175c51577a326946939f4d-%E7%BC%96%E8%BE%91%E8%B7%9D%E7%A6%BB.jpg)


### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
    int len1 = word1.size();
    int len2 = word2.size();
    

    int dp[len1+1][len2+1] = {0}; //大小一定要加1，为0行0列留出位置
    for(int i = 0;i <= len1;i++){
        dp[i][0] = i;
    }

    for(int j = 0;j <= len2;j++){
        dp[0][j] = j;
    } 

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if (word1[i-1] == word2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min( dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]) );
            }
        }
    }

    return dp[len1][len2];
    }

};
```