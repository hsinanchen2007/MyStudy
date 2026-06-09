### 解题思路
回逆遍历所有的可能分割情况,然后每次判断子串是否满足回文条件,满足条件则继续递归判断,不满足直接返回.

### 代码

```cpp
class Solution {
public:
    bool check(string s){
        if(s.size()==1)
            return true;
        int i=0,j=s.size()-1;
        while(i<j){
            if(s[i]!=s[j])
                return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    void core(string s,vector<string>vct,vector<vector<string>>&res,
              int st){
        int n=s.size();
        if(st==n){
            if(vct.size()>=1)
                res.push_back(vct);
            return;
        }
        for(int i=st;i<n;i++){
            string str=s.substr(st,i-st+1);
            if(check(str)){
                vct.push_back(str);
                core(s,vct,res,i+1);
                vct.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string>vct;
        vector<vector<string>>res;
        if(s.size()==0)
            return res;
        core(s,vct,res,0);
        return res;
    }
};
```