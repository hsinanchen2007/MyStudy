### 解题思路
此处撰写解题思路

### 代码

```cpp
struct cmp
{
    bool operator() (const pair<int, int> &lhs, const pair<int, int> &rhs)
    {
        return lhs.second < rhs.second;  //构建大顶堆
    }
};
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        if(nums.size() == 0 || k < 1)return {};
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        unordered_map<int, int> um;
        vector<int> res;
        for(auto c : nums)
        {
            if(um.find(c) == um.end())
            {
                um.insert(pair<int, int>(c, 1));
            }
            else
            {
                ++um[c];
            }
        }
        for(auto it = um.begin(); it != um.end(); ++it)
        {
            pq.push(pair<int, int>(it->first, it->second));  //注意这里不用加*
        }
        while(k--)
        {
            res.push_back(pq.top().first);  //注意这里不要->，而是.
            pq.pop();
        }
        return res;
    }
};
```