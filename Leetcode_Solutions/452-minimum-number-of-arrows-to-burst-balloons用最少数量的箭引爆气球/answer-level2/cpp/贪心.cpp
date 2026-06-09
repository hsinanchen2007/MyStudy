### 解题思路
先将坐标数组按右端点的大小升序排列，然后每次开枪打气球的右端点last，那么排在后面的（右端点更大）左端点小于等于last的气球都会破掉。然后找到下一个未破的气球打它的右端点，直到所有气球都破了为止。

### 代码

```cpp
class Solution {
    static bool cmp(vector<int>a,vector<int>b){
        if(a[1]==b[1]) return a[0]<b[0];
        return a[1]<b[1];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0) return 0;
        sort(points.begin(),points.end(),cmp);
        int res=1,last=points[0][1];
        for(int i=1;i<points.size();i++){
            if(last>=points[i][0]) continue;
            res++;
            last=points[i][1];
        }
        return res;
    }
};
```