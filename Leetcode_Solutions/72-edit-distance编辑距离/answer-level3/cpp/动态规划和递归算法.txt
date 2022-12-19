### 解题思路
经典的距离题目
编辑距离的题目，第一还是找出相邻关系，即最终所求的结果与前一元素结果的关系，然后动态规划每一步，从开始到结果；
添加了备忘录的的递归方式执行效率也不太好，主题思路与动态规划很像，从结果到前面推。(这里参考一位同学的代码)。

编辑距离是重点算法题，之前还有一题类似的题44.通配符匹配与本题类似，都是很好的锻炼题。
### 代码

```cpp
class Solution {
private:
    unordered_map<int, unordered_map<int, int>> demo;
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==0) return n;
        if(n==0) return m;
        int res = ij(word1,word2,m,n);
        return res;
        
    }
    int ij(string word1,string word2,int i,int j){
        if(demo.count(i)>0&&demo[i].count(j)>0){
            return demo[i][j];
        }
        if(i==0||j==0){
            return i==0? j:i;
        }
        int res;
        if(word1[i-1]==word2[j-1]){
            res = ij(word1,word2,i-1,j-1);
        }
        else{
            res = min(ij(word1,word2,i-1,j-1),min(ij(word1,word2,i,j-1),ij(word1,word2,i-1,j)))+1;
        }
        demo[i][j] = res;
        return res;
    }
};
动态规划
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        if(m==0) return n;
        if(n==0) return m;
        int dp[m+1][n+1];
        memset(dp, 0, (m+1)*(n+1));
        for(int i=1;i<=m;i++){
            dp[i][0] = i;
        }
        for(int i=1;i<=n;i++){
            dp[0][i] = i;
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                }
            }
        }
        return dp[m][n];
    }
};
```