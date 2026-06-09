### 解题思路
此处撰写解题思路
cpp二维数组的new 
int **dp = new int*[len1+1];
for(int i=0; i<=len1; ++i) dp[i] = new int[len2+1];
还可以用数组指针 char (*pa)[4]; pa是指向char[4]，pa+1，意味移动四个char，数组指针常用作函数传二维数组的参数。
string []没有out-range检查，at(i)有。
### 代码

```cpp
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int **dp = new int*[len1+1];
        for(int i=0; i<=len1; ++i) dp[i] = new int[len2+1];
        for(int i=0; i<=len1; ++i) dp[i][0] = i;
        for(int j=0; j<=len2; ++j) dp[0][j] = j;

        for(int i=1; i<=len1; ++i){
            for(int j=1; j<=len2; ++j){
                if(word1[i-1]==word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = 1 + std::min(std::min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                }
            }
        }
        return dp[len1][len2];
    }
};
```