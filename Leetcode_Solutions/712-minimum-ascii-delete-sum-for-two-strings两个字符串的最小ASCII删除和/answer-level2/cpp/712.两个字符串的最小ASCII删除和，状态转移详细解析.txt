dp[i][j]记录了s1[i:]和s2[j:]两个子串的最小ASCII删除和，dp[0][0]代表了s1和s2的最小删除和
<注：思路师承官方题解，但对于状态转移公式有更详细说明。如对code有疑问，还可结合参考官方题解>
考虑dp[i+1][j]和dp[i][j]之间的关系： 
case1:
若s1[i]!=s2[j]，最前端字符不匹配，必有一个字符被删除，总代价提高。 
Q:为何不认为s1[i+1:]也没有与s2[j+1:]匹配但s1[i]==s2[j+1]呢？ 
A:这里的状态转移式为:dp[i][j]=min(s1[i]+dp[i+1][j],s2[j]+dp[i][j+1])
  将s1[i:]和s2[j:]头对齐，若s1[i]!=s2[j]，s1[i]或s2[j]肯定会被删除，状态转移式包含了所有情况。

case2:
若s1[i]==s2[j]，分两种情况： 
1.如果s1[i+1]!=s1[i]，则s1[i]字符的引入能够做到s1[i+1:]未能做到的事：与s2[j]匹配,dp[i][j]=dp[i+1][j+1] 
2.如果s1[i+1]==s1[i],则s1[i]字符做到了s1[i+1:]字符串能做到的事:与s2[j]匹配。此时最小代价等同于s1[i+1][j+1]。dp[i][j]=dp[i+1][j+1]

综上，若s1[i]==s2[j]，则dp[i][j]=dp[i+1][j+1] 否则，dp[i][j]=min(s1[i]+dp[i+1][j],s2[j]+dp[i][j+1])

class Solution {
public:
    int count(string s,int begin,int end)   //[begin,end)
    {
        int sum=0;
        for(int i=begin;i<end;i++)  sum+=(int)s[i];
        return sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        int s1_len=s1.length();    int s2_len=s2.length();
        if(!s1_len)    return count(s2,0,s2_len);
        if(!s2_len)    return count(s1,0,s1_len);
        vector<vector<int>>dp(s1_len+1,vector<int>(s2_len+1,0));
        for(int i=s1_len-1;i>=0;i--)   dp[i][s2_len]=dp[i+1][s2_len]+(int)s1.at(i);
        for(int j=s2_len-1;j>=0;j--)     dp[s1_len][j]=dp[s1_len][j+1]+(int)s2.at(j);
        for(int i=s1_len-1;i>=0;i--)
        {
            for(int j=s2_len-1;j>=0;j--)
            {
                if(s2.at(j)==s1.at(i))  dp[i][j]=dp[i+1][j+1];
                else    dp[i][j]=min(dp[i+1][j]+(int)s1.at(i),dp[i][j+1]+(int)s2.at(j));
            }
        }
        return dp[0][0];
    }
};
