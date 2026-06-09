### 解题思路
同题435，找所有不重叠的区间的个数，因为如果重叠，可用一支箭引爆重叠的气球。当只有边界重合时也属于重叠
将points按照Xend从小到大排序，计算最多的不重叠的区间。

### 代码

```cpp
class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
           return 0;
        sort(points.begin(),points.end(),cmp);
        int end=points[0][1];
        int count=1;
        for(int i=1;i<points.size();i++){
            if(points[i][0]<=end)
               continue;
            else{
                end=points[i][1];
                count++;
            }
        }
        return count;
    }
};
```