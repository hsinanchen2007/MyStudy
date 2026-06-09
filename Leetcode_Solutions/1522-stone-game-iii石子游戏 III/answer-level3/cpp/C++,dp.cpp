#### 简单理解就是A与B之间都追求两者之间分数差值要尽可能的大，这样自己的优势才是最大的。。。
#### 最后判断dp[0]的原因是，最初Alice先选，之后Bob选的都是之前dp更新过的，在dp[i]位置处的最佳的选择，Bob说白了没有别的选择了，只能按照之前更新的Dp进行选择。。。。
#### 思路有点像先构造Dp，之后再进行相应的选择。。。
```
class Solution {
public:
//我的解题思路是，两个人之间拿的分数的差值作为dp[i],差值大的为我们所求的，因为差值越大代表的我的得分和对手的得分差值越多
    string stoneGameIII(vector<int>& a) {
        int n=a.size();
        vector<int>dp(1e6,0);
        for(int i=n-1;i>=0;i--){//先从后往前构造一个dp，最优的dp，之后遍历这个最有的dp求出解。。。
            dp[i]=-1e9;
            int sum=0;
            for(int j=0;j<3&&j+i<n;j++){
                sum+=a[i+j];
                dp[i]=max(dp[i],sum-dp[i+j+1]);
            }
        }
        if(dp[0]>0)return "Alice";
        if(dp[0]<0)return "Bob";
        return "Tie";
    }
};
```