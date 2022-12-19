### 解题思路
此处撰写解题思路

### 代码

```cpp

class Solution {
public:
    
    bool canMeasureWater(int x, int y, int z) {
        // 记录已经出现过的状态
        unordered_map<int,unordered_set<int>>seen;
        // 记录待搜索的状态
        stack<pair<int,int>>s;
        // 初始化两个容器均为空
        s.push({0,0});
        while(!s.empty())
        {
            
            auto p = s.top();
            s.pop();
            if(seen[p.first].count(p.second)) continue;
            seen[p.first].insert(p.second);
            
            int remain_x = p.first;
            int remain_y = p.second;
            
            if(remain_x == z || remain_y == z || remain_x + remain_y == z)
                return true;
            
            // 6种状态
            
            s.push({x,remain_y});
            
            s.push({remain_x,y});
           
            s.push({0,remain_y});
            
            s.push({remain_x,0});
           
            int x_ , y_;
            x_ = remain_x - min(remain_x,y-remain_y);
            y_ = remain_y + min(remain_x,y-remain_y);
            
            s.push({x_,y_});
            
            x_ = remain_x + min(remain_y,x-remain_x);
            y_ = remain_y - min(remain_y,x-remain_x);
            
            s.push({x_,y_});
            
        }
        return false;

    }
};
```