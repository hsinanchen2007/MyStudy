### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<string> v;
    string ss;
    void dfs(string &s,int index,int n,string ss){
       if(index>=n)
       {     
             v.push_back(ss);
             return;
       }
       if(isalpha(s[index])){
             ss+=tolower(s[index]);
             dfs(s,index+1,n,ss);
             ss[ss.size()-1]=toupper(s[index]);
             dfs(s,index+1,n,ss);
        }
        else{
             dfs(s,index+1,n,ss+s[index]);
        }
    }
    vector<string> letterCasePermutation(string S) {
            dfs(S,0,S.size(),ss);
            return v;
    }
};
```