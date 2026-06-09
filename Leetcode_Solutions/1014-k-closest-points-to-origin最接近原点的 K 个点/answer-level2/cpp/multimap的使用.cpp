
### 代码

```cpp
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        multimap<int,vector<int>> help;
        vector<vector<int>> ans;

        //利用multimap的自动排序性
        for(vector<int> point:points)
            help.insert(pair<int,vector<int>>(point[0]*point[0]+point[1]*point[1],point));
        
        multimap<int,vector<int>>::iterator it=help.begin();

        while(K>0)
        {
            ans.push_back(it->second);
            it++;
            K--;
        }

        return ans;
    }
};
```