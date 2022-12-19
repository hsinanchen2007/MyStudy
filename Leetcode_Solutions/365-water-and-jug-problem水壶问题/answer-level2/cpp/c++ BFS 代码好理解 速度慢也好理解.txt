### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    struct pair_hash
    {
        size_t operator() (const pair<int, int>& p) const
        {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };
    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z) return false;
        if(x == z || y == z || z == 0) return true;
        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, pair_hash> v;
        q.push({0, 0});
        while(!q.empty())
        {
            pair<int, int> p = q.front();
            q.pop();
            int cur_x = p.first;
            int cur_y = p.second;
            if(cur_x + cur_y == z || cur_x == z || cur_y == z) return true;
            //装满a
            if(!v.count({x, cur_y}))
            {
                v.insert({x, cur_y});
                q.push({x, cur_y});
            }
            //装满b
            if(!v.count({cur_x, y}))
            {
                v.insert({cur_x, y});
                q.push({cur_x, y});
            }
            //清空a
            if(!v.count({0, cur_y}))
            {
                v.insert({0, cur_y});
                q.push({0, cur_y});
            }
            //清空b
            if(!v.count({cur_x, 0}))
            {
                v.insert({cur_x, 0});
                q.push({cur_x, 0});
            }
            //a入b
            int m = min(cur_x, y - cur_y);
            if(!v.count({cur_x - m, cur_y + m}))
            {
                v.insert({cur_x - m, cur_y + m});
                q.push({cur_x - m, cur_y + m});
            }
            //b入a
            m = min(x - cur_x, cur_y);
            if(!v.count({cur_x - m, cur_y + m}))
            {
                v.insert({cur_x + m, cur_y - m});
                q.push({cur_x + m, cur_y - m});
            }
        }
        return false;
    }
};
```