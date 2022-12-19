
```cpp
class Solution {
public:
    unordered_set<size_t>set;
    queue<pair<int, int>>q;
    //入队列
    void canMeasureWater_(int x,int y){
        size_t key = (size_t)x * 100000007 + y;
        if(set.find(key) == set.end()){
            set.insert(key);
            q.push({x,y});
        }
    }
    
    bool canMeasureWater(int x, int y, int z) {
        //水不够
        if(x + y < z) return false;
        if(x == z || y == z || z == 0) return true;
        //2个水杯一样 ，没法折腾
        if(x == y && x + y != z) return false;
        canMeasureWater_(0, 0);
        while (!q.empty()) {
            auto top = q.front();
            int cur_x = top.first;
            int cur_y = top.second;
            q.pop();
            
            if(cur_x + cur_y == z || cur_x == z || cur_y == z) {
                return true;
            }
            //装满a
            canMeasureWater_(x, cur_y);
            //装满b
            canMeasureWater_(cur_x, y);
            //清空a
            canMeasureWater_(0, cur_y);
            //清空b
            canMeasureWater_(cur_x, 0);
            //a到入b
            int a = min(cur_x, y - cur_y);
            canMeasureWater_(cur_x - a, cur_y + a);
            
            //b到入a
            int b = min(cur_y, x - cur_x);
            canMeasureWater_(cur_x + b, cur_y - b);
        }
        return false;
    }
};
```