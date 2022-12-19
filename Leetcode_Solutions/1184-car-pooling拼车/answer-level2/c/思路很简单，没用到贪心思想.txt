### 解题思路
1. 路程最大1000，所以建一个1000的数组表示在这个位置车上的人数
2. 根据trips的信息，如果是起始就加这么多人，如果到终点减这么多人
3. 遍历数组如果在那个位置车上的人多于最大值就返回错误否则OK

### 代码

```cpp
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int map[1001],cur=0;
        memset(map,0,sizeof(map));
        for (int i=0;i<trips.size();i++){
            map[trips[i][1]] += trips[i][0];
            map[trips[i][2]] -= trips[i][0];
        }
        for (int i=0;i<1001;i++){
            cur += map[i];
            if (cur>capacity)
                return false;
        }
        return true;
    }
};
```