### 解题思路
4ms

### 代码

```cpp
class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination)
    {
        int n = distance.size();
        if (start > destination) //保证start不大于destination
        {
            int tmp = start;
            start = destination;
            destination = tmp;
        }
        int a = 0, b = 0;
        //计算正反向走
        for (int i = start; i < destination; i++)
            a += distance[i];
        //计算反方向走
        for (int i = 0; i < start; i++)
            b += distance[i];
        for (int i = destination; i < n; i++)
            b += distance[i];
        return min(a, b);
    }
};
```