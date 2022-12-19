```
class Solution {
public:
    int res;
    map<string ,set<char>>m;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(int i=0;i<allowed.size();++i)
        {
            m[allowed[i].substr(0,2)].insert(allowed[i][2]);

        }
        dfs(bottom,"",0);
        return res;
    }
    void dfs(string bottom,string next,int x)
    {   
        if(res==1)
        return;//信号枪，不加这句会超时
        if(bottom.length()==1)
        {
            res=1;
            return;
        }
        if(x==bottom.length()-1)
        {
            dfs(next,"",0);
        }
        else
        {     
            
             int len=m[bottom.substr(x,2)].size();
             
             for(auto i=m[bottom.substr(x,2)].begin();i!=m[bottom.substr(x,2)].end();++i)
             {
                 dfs(bottom,next+*i,x+1);//逐块递归
             }

        }
        
    }
};
```
