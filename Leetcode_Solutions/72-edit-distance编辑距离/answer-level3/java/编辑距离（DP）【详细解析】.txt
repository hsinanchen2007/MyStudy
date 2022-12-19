### 解题思路
思路很简单，就是**动态规划**，填表，**由子问题的最优解推出原问题的最优解**。

【借图】
![76574ab7ff2877d63b80a2d4f8496fab3c441065552edc562f62d5809e75e97e-Snipaste_2019-05-29_15-28-02.png](https://pic.leetcode-cn.com/26784befa06941ff7449f29a2680c8e281b54fdd834059923621a6f03a3eb3d1-76574ab7ff2877d63b80a2d4f8496fab3c441065552edc562f62d5809e75e97e-Snipaste_2019-05-29_15-28-02.png)

1. 首先可以填出上述表格，可理解为一方为空时，要使两方相等需要经过多少次变换（易知，此处只需在另一方删除元素或在空白方加入元素）。
2. 接下来就开始使用动态规划的算法了，数组的i行j列代表要使`word1的前i个元素`与`word2的前j个元素`通过变换变成相同的字符串最少需要多少次变换，而该问题的最优解可以转化为其子问题的最优解。

# 分两种情况讨论：
- ***当前元素相同时***，在当前元素上已经不需要再进行变换了，其子问题`dp[i-1][j-1]`的最优解就是此问题的最优解(因为当前元素从上述状态转换过来不需要进行任何变换，只需要再尾部添加相同元素即可，最优解相同)。
- ***当前元素不同时***，则需另行考虑：
    1. **考虑从dp[i-1][j-1]变换过来是最优策略。**在此方案中，`word1的前i-1个元素`和`word2的前j-1个元素`变换为相同字符串的最优解已经求出，而此时在两个字符串后各加一个字符（不同的字符，相同的已经考虑过了），而问题就变成了将两个字符变换为相同字符需要进行几次操作，显而易见，1次，即替换其中一个。在这种策略中，`dp[i][j]=dp[i-1][j-1]+1`
    2. **考虑从dp[i][j-1]变换过来（从左边过来）是最优策略。**在此方案中，`word1的前i个元素`和`word2的前j-1个元素`变换为相同字符串的最优解已经求出，而此时的`dp[i][j]`就是在`word2的前j-1个元素`组成的字符串的后面加上一个字符，然后还要使他们相等，求出此时的最优策略，易知，也只需要进行1步操作，即将增加的这位`在word2中删去or在word1中增加一个相同元素`，使其相同。
    3. **考虑从dp[i-1][j]变换过来（从上面过来）是最优策略。**同上，此处不再赘述。

    *而现在问题就分析的很透彻了，当前元素相同的时候直接`dp[i][j]=dp[i-1][j-1]`,不同的时候取三种情况中最优的那一个，就可以得到该问题的最优解。*

# 填表方式：
    因为*填当前位置需要知道`左、左上、上`三个位置的值*，故可按行优先一行一行往下填，也可按列优先，一列一列往右填。

# 代码如下：

### 代码

```C++ []
class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1len=word1.size(),w2len=word2.size();
        int dp[w1len+1][w2len+1];
        for(int i=0;i<=w1len;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=w2len;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=w1len;i++){
            for(int j=1;j<=w2len;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j]=dp[i-1][j-1];//当前元素相等，不用算
                }
                else{//取最小值
                    dp[i][j]=1+myMin(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[w1len][w2len];
    }
    int myMin(int a,int b,int c){//求三值最小
        if(a>b)a=b;
        if(a>c)a=c;
        return a;
    }
};
```
```JAVA []
class Solution {
    public int minDistance(String word1, String word2) {
        int w1len=word1.length(),w2len=word2.length();
        int dp[][]=new int[w1len+1][w2len+1];
        for(int i=0;i<=w1len;i++){
            dp[i][0]=i;
        }
        for(int i=0;i<=w2len;i++){
            dp[0][i]=i;
        }
        for(int i=1;i<=w1len;i++){
            for(int j=1;j<=w2len;j++){
                if(word1.charAt(i-1)==word2.charAt(j-1)){
                    dp[i][j]=dp[i-1][j-1];//当前元素相等，不用算
                }
                else{//取最小值
                    dp[i][j]=1+myMin(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[w1len][w2len];
    }
    public int myMin(int a,int b,int c){//求三数最小值
        if(a>b)a=b;
        if(a>c)a=c;
        return a;
    }
}
```
