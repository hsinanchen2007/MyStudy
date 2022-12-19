### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
vector<string> ret;
int z = 0;
public:
    bool panduan(string ss){
        int n = ss.length();
        int booll =0;
        for(int i = 0;i<n;i++){
            if(ss[i]=='('){
                booll++;
            }
            else {
                booll--;
            }
            if(booll<0){
                return false;
            }
        }
        if(booll==0){
            return true;
        }
        return false;
    } 
    void dfs(int n,string tem){
        if(tem.length()>=n*2){
            if(panduan(tem)){
                ret.push_back(tem);
            }
            return ;
        }
        dfs(n,tem+"(");
        dfs(n,tem+")");
    }
    vector<string> generateParenthesis(int n) {
        dfs(n,"(");
        return ret;
    }
};
```