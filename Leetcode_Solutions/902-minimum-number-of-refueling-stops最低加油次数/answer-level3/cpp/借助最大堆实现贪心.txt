### 解题思路
1. 终点不在数组中，需要手动添加，油量可设置为0，不然就需要在判断完加油站之后再判断能不能达到终点；
2. 借助最大堆选择加油站；
3. 贪心能够经过的加油站中油量最多的。

### 代码

```cpp
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        if(stations.size()==0&&startFuel<target)
            return -1;
        priority_queue<int> max_heap;
        stations.push_back(vector<int> {target,0});//需要手动添加终点，终点油量设置为0
        int ans=0,pre_location=0;
        for(auto station:stations)
        {
            int loaction=station[0];
            int fuel=station[1];
            startFuel-=(loaction-pre_location);//loaction记录的是所有走过的路程，此处只需要记录加油站之间的距离
            while(startFuel<0&&!max_heap.empty())//取出能够经过的加油站中油量最多的
            {
                startFuel+=max_heap.top();
                max_heap.pop();
                ans++;
            }
            if(startFuel<0) return -1;//不能到达下一个加油站
            max_heap.push(fuel);//到达之后才能入堆
            pre_location=loaction;
        }
        
        return ans;

    }
};
```