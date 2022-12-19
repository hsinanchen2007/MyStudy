### 解题思路
并查集，进行分组，用map进行存储分组

### 代码

```cpp
#include<map>
class Solution {
    int n;
    map<char,char> mp;
    bool flag=true;
public:
    bool equationsPossible(vector<string>& equations) {
        n=equations.size();
        for(int i=0;i<n;i++){
            mp[equations[i][0]]=equations[i][0];
            mp[equations[i][3]]=equations[i][3];
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!'){
                continue;
            }else{
                merge(equations[i][0],equations[i][3]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(equations[i][1]=='!'&&getf(equations[i][0])==getf(equations[i][3])){
                flag=false;
                break;
            }
            if(equations[i][1]=='='&&getf(equations[i][0])!=getf(equations[i][3])){
                flag=false;
                break;
            }
        }
        return flag;

    }
    void merge(char u,char v){
        char t1=getf(u);
        char t2=getf(v);
        if(t1!=t2){
            mp[t2]=t1;
        }
        return;
    }
    char getf(char u){
        if(mp[u]==u){
            return u;
        }else{
            mp[u]=getf(mp[u]);
            return mp[u];
        }
    }
};
```