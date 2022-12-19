### 解题思路
c++暴力bfs

### 代码

```cpp
class Solution {


public:
    queue<int> que;
    set<int> appear;
    int bfs(int target,int t,int curt,vector<int>& prop,unordered_map<int,vector<int>>& _map)
    {        
        while(curt<t)
        {
            queue<int> next;
            while(!que.empty())
            {
                    int temp = que.front();
                    que.pop();
                    int len = _map[temp].size();
                    int flag =0;int count = 0;
                    for(int i=0;i<_map[temp].size();i++)
                    {
                        if(!appear.count(_map[temp][i]))count++;
                    }
                    for(int i=0;i<_map[temp].size();i++)
                    {
                        if(!appear.count(_map[temp][i])){
                            next.push(_map[temp][i]);
                            prop[_map[temp][i]] = prop[temp] * count;
                            appear.insert(_map[temp][i]);                            
                        }
                    }
                    if(count>0)prop[temp]=0;
            }
        
            while(!next.empty())
            {
                que.push(next.front());
                next.pop();
            }
            curt++;
        }
            return prop[target];
    }
    
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>> _map;
        for(int i=0;i<edges.size();i++)
        {
            if(_map.count(edges[i][0]))
            {_map[edges[i][0]].push_back(edges[i][1]);}
            else
            {_map[edges[i][0]]={edges[i][1]};}
            if(_map.count(edges[i][1]))
            {_map[edges[i][1]].push_back(edges[i][0]);}
            else
            {_map[edges[i][1]]={edges[i][0]};}
            
        }
        vector<int> prop(101);
        prop[1]=1;
        que.push(1);appear.insert(1);
        int div = bfs(target,t,0,prop,_map);
        if(div==0)return 0;
        double ans = 1/(double)div;
    return  ans;}
};
```