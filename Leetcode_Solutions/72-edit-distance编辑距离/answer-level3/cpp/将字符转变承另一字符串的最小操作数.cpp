### 解题思路
本题抓住核心是一般遇到两个字符串问题，用双指针分别指向字符串的末尾，然后从后往前开始遍历，反过来也一样。这道题还需要注意的一点是无论是字符A转变成B还是B变A，操作数是相等的。
该题的思路是用动规，假设dp[i][j]是word1第i个字符串和word2第j个字符串处所需要变动的操作数最小值，则当第i和j的字符相等时可直接跳过遍历下一个，不等时就进行删除插入或者替换，完成上述三个中任一个操作都会导致操作数加1，以及i\j的相应变化，如此就写出了状态转移方程，然后找到i或j为0的时候的base情况，串起来就OK了
代码部分注意定义dp数组的时候，如果用内置类型int[][]，括号内应为常量，.size()会报错，所以用vector得了，就是初始化方式有点复杂。以及该题dp数组由于[0][0]对应的是没有任何字符，所以要多出1来，相应在代码循环和索引上会发生变化，要小心

### 代码

```cpp

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp (word1.size()+1,vector<int>(word2.size() + 1,0));
        for(int i=1;i<=word1.size();i++){
            dp[i][0] = i;
        }
        for(int j=1;j<=word2.size();j++){
            dp[0][j] = j;
        }
        for(int i=1;i<=word1.size();i++){
            for(int j=1;j<=word2.size();j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min_three(dp[i][j-1],dp[i-1][j-1],dp[i-1][j])+1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
private:
    int min_three(int a,int b,int c){
        return min(min(a,b),c);
    }
};

```