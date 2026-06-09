### 解题思路
并查集，通过对下表进行分组即可，每组内字符按字典序排列

### 代码

```cpp
#include<queue>
#include<map>
#include<string>
class Solution {
    int f[100005];
    int n;
    map<int,priority_queue<char,vector<char>,greater<char>>> mp;
    string result="";
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        n=s.size();
        init();
        for(int i=0;i<pairs.size();i++){
            merge(pairs[i][0],pairs[i][1]);
        }
        for(int i=0;i<n;i++){
            mp[getf(i)].push(s[i]);
        }
        for(int i=0;i<n;i++){
            result+=mp[getf(i)].top();
            mp[getf(i)].pop();
        }
        return result;

    }
    void init(){
        for(int i=0;i<n;i++){
            f[i]=i;
        }
        return;
    }
    int getf(int u){
        if(f[u]==u){
            return u;
        }else{
            f[u]=getf(f[u]);
            return f[u];
        }
    }
    void merge(int u,int v){
        int t1=getf(u);
        int t2=getf(v);
        if(t1!=t2){
            f[t2]=t1;
        }
        return;
    }

    
};
```