### 解题思路

选定一个原点，hashmap记录其他所有点到这个点之间的距离。
此处优化：A->B距离=B->A距离，可以减少一般的时间消耗，但是需要额外空间去储存。

eg:
```
 点的个数    新增个数      总的个数
    1           0           0
    2         1*2=2         2  
    3         2*2=4         6
    4         3*2=6         12
    5         4*2=8         20
```

新增满足条件的点的个数公式：
（前一次满足条件个数-1）*2


### 代码

```cpp
class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int size=points.size();
        if(size<3) return 0;
        vector<unordered_map<int,int>> tmp(size,unordered_map<int,int>{});
        int count=0;
        for(int i=0;i<size;++i){
            for(int j=i+1;j<size;++j){
                int dis=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
                ++tmp[i][dis];
                ++tmp[j][dis];
                count+=((tmp[i][dis]-1)*2);
                count+=((tmp[j][dis]-1)*2);
            }
        }
        return count;
    }
};
```