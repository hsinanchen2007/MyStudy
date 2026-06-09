- ### DFS
遍历字符串，假设`0-i`组成的字符串在`wordDict`中出现过，那么再递归查找`i+1`到`s.size()`。当然了，如此简单的想法自然是会超时的
```
//dfs超时
class Solution {
public:
    bool isExit(string s1,vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s1==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    bool helper(string &s,vector<string>& wordDict,int start){
        if(start==s.size())return true;
        for(int i=start;i<=s.size();i++){
            if(isExit(s.substr(start,i-start),wordDict)){
                if(helper(s,wordDict,i))return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
         return helper(s,wordDict,0);
    }
};
```
- ### 动态规划
递归超时，主要原因就是做了大量重复查找，同一个区间的字符串查找了不知道几百回。所以我们能不能想一种方法：让他相同的字符串查找的次数少一点。方法肯定是有的，比如备忘录解法（一定是我太菜了，备忘录也超时），再或者就是传说中的DP大法。接下来就说一下DP
- `dp`数组的大小设为`s.size()+1`,并初始化`dp[0]=true`
- `dp[i]=true`说明到i为止，字符串是可以用`wordDict`中的单词构成的
- 如果`s[i:j]`也以由`wordDict`中单词组成，并且`s[:i]`也可以由`wordDict`中单词组成,那么将`dp[j]`也设为`true`
```
//动态规划
class Solution {
public:
    bool isExit(string s1,vector<string>& wordDict){
        for(int i=0;i<wordDict.size();i++){
            if(s1==wordDict[i]){
                return true;
            }
        }
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool>dp(s.size()+1,false);
        dp[0]=true;
        for(int i=1;i<=s.size();i++){
            for(int j=i;j>=0;j--){
                if(isExit(s.substr(j,i-j),wordDict)&&dp[j]){
                    dp[i]=true;break;
                }
            }
        }
        return dp[s.size()];
    }
};
```
