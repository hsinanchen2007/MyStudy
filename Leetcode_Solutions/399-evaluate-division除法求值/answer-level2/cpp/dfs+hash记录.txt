### 解题思路

太头疼了，花了我好长的时间呀。

### 代码

```cpp
class Solution {
public:
    vector<double> ret;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        ret=vector<double>(queries.size(),-1.0);
        unordered_map<string,bool> m;
        for(int i=0;i<queries.size();i++){
            m.clear();
            for(auto idx:equations){
                string str=idx[0]+','+idx[1];
                m.insert({str,false});
            }
            bool retFlag=false;
            dfs(equations,values,m,i,queries[i][0],queries[i][1],1,retFlag);
        }
        return ret;
    }

    void dfs(vector<vector<string>>& equations,
     vector<double>& values,
    unordered_map<string,bool>& m,
    int idx,
     string u, 
     string d,
     double val,
     bool& retFlag){
        for(int i=0;i<equations.size();i++){
            if(retFlag) return;
            if(equations[i][0].compare(u)==0){
                if(u==d){
                     ret[idx]=1;
                        retFlag=true;
                        return;
                }
                string str=equations[i][0]+','+equations[i][1];
                if(m[str]){
                    continue;
                }else{
                    m[str]=true;
                    if(equations[i][1].compare(d)==0){
                        ret[idx]=val*values[i];
                        retFlag=true;
                        return;
                    }
                    dfs(equations,values,m,idx,equations[i][1],d,val*values[i],retFlag);
                    m[str]=false;
                } 

            }
        }

        for(int i=0;i<equations.size();i++){
            if(retFlag) return;
            if(equations[i][1].compare(u)==0){
                if(u==d){
                     ret[idx]=1;
                        retFlag=true;
                        return;
                }
                string str=equations[i][0]+','+equations[i][1];
                if(m[str]){
                    continue;
                }else{
                    m[str]=true;
                    if(equations[i][0].compare(d)==0){
                        ret[idx]=val/values[i];
                        retFlag=true;
                        return;
                    }else{
                        dfs(equations,values,m,idx,equations[i][0],d,val/values[i],retFlag);
                    }
                    m[str]=false;
                } 

            }
        }
    }
};
```