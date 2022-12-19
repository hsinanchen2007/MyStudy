参考官方题解

# 一.回溯法(注意剪枝的方法，否则会超时)
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<int>flag(s.size(),0);//*******
      return help(s,0,wordDict,flag);  
    }
    bool help(string s,int l,vector<string>&dict,vector<int>&flag)
    {
        if(l>=s.size())return true;
        if(flag[l])return false;
        for(int i=0;i<dict.size();++i)
        {  
            if(s.substr(l,dict[i].size())==dict[i])
            {
                
               if( help(s,l+dict[i].size(),dict,flag))return true;
               else flag[l]=1;
                
            }
        }
        return false;
    }
};
```
# 二.DFS(和二叉树的广度优先遍历一样。和上一种方法一样，同样需要记录访问过的元素，降低复杂度)
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       queue<int>qs;
        qs.push(0);
       unordered_set<string>us(wordDict.begin(),wordDict.end());
        vector<int>visited(s.size()+1,0);                   //******
        while(!qs.empty())
        {
            auto start=qs.front();
             qs.pop();
            if(start==s.size())return true;
            for(int end=start;end<=s.size();++end)
            {   
                if(visited[end]==0&&us.find(s.substr(start,end-start))!=us.end())
                {qs.push(end);visited[end]=1;}
            }
            
        }
        return false;
    }
};
```
# 三 .动态规划
```
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> us(wordDict.begin(),wordDict.end());
        vector<int>dp(s.size()+1,0);
        dp[0]=1;
        for(int i=1;i<=s.size();++i)
        {
            for(int j=0;j<i;++j)
            {
                if(dp[j]==1&&us.find(s.substr(j,i-j))!=us.end())
                {
                    dp[i]=1;
                    break;
                }
            }
        }
        if(dp[s.size()]==1)return true;
        return false;
    }
};
```





