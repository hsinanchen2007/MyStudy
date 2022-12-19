### 解题思路
使用了一些c++11特性
注:可能存在相同的机票，即出发地和目的地相同，使用multiset(默认从大到小排序)
### 代码

```cpp
class Solution 
{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) 
    {
        map<string,multiset<string>> nodes;
        vector<string> res;
        for(auto t:tickets) nodes[t[0]].insert(t[1]);
        DFS(nodes,"JFK",res);
        reverse(res.begin(),res.end());
        return res;
    }

    void DFS(map<string,multiset<string>>& nodes,string from,vector<string>& res)
    {
        while(!nodes[from].empty())
        {
            string next=*nodes[from].begin();
            nodes[from].erase(nodes[from].begin());
            DFS(nodes,next,res);
        }
        res.push_back(from);
    }
};
```