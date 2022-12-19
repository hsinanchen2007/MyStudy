### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    vector<vector<string>> v;
    vector<string> v1;
    bool ishuiwen(int l,int r,string &s){
        int k=0;
        for(int i=l;i<=(l+r)/2;++i){
            if(s[i]!=s[r-k])
               return false;
            k++;
        }
        return true;
    }
    void dfs(string &s,int index){
        if(index>=s.size()){
            v.push_back(v1);
            return;
        }
        for(int i=index;i<s.size();++i){
            if(ishuiwen(index,i,s)){
                v1.push_back(s.substr(index,i-index+1));
                dfs(s,i+1);
                v1.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
          dfs(s,0);
          return v;
    }
};
```