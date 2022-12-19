# ***速度较慢,仅供参考***
```
class Solution {
public:
    int numDistinct(string s, string t) {

        int k = 0;
        vector<vector<int>>v(s.size(),vector<int>(t.size(),-1));
        return dfs(s,t,0,0,v);
    }
    int dfs(string s, string t,int indexs,int indext,vector<vector<int>>&v){
        if(indext==t.size()){
            return 1;
        }
        if(indexs==s.size()){
            return 0;
        }
        if(v[indexs][indext]!=-1){
            return v[indexs][indext];
        }
        int k=0;
        if(s[indexs]==t[indext]){
            k+=dfs(s,t,indexs+1,indext+1,v);
        }
        k+=dfs(s,t,indexs+1,indext,v);
        v[indexs][indext]=k;
        return k;
    }
};
```
