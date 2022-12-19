首先来看暴力回溯，见代码1。提交之后显示超时。具体原因是卡在了[aaaaaa.....aaab]这个测试用例上
那么究竟是为什么呢。
  拿[aaaab]来举例，它可分为["a","a","aab"],["aa","aab"],两个都包含了"aab",所以就产生了重复的
递归。这时，就可以用一个哈希表记录"aab"这种情况。当再次递归时，先判断一下，如果是"aab",就直接返回。
代码2就是加了哈希表的记忆化回溯。加粗部分为比代码一增添的部分。仅仅添加几行代码，完美通过。

代码1：
```
class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict ) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        return dfs(s, wordDict,m);
    }
     bool dfs(string s,vector<string>&wordDict ,unordered_set<string> m)
    {
        if(s.empty())
        {
            return true;
        }
        for(int i=1;i<=s.size();i++)
        {
            string temp=s.substr(0,i);
              if(m.find(temp) != m.end() )  
              {
                  return true;
              }
        }
        return false;
    }  
};
```



代码2：
```
class Solution {
public:
 ** unordered_map<string,bool>map;**
  bool wordBreak(string s, vector<string>& wordDict ) {
        unordered_set<string> m(wordDict.begin(), wordDict.end());
        return dfs(s, wordDict,m);
    }
     bool dfs(string s,vector<string>&wordDict ,unordered_set<string> m)
    {
        if(s.empty())
        {
            return true;
        }
       ** if(map[s])return false;**
        for(int i=1;i<=s.size();i++)
        {
            string temp=s.substr(0,i);
              if(m.find(temp) != m.end() )  
              {
                ** if(!dfs(s.substr(i),wordDict,m))**
                    **map[s.substr(i)]=true;**
                  else return true;
              }
        }
        return false;
    }  
};
```
```

