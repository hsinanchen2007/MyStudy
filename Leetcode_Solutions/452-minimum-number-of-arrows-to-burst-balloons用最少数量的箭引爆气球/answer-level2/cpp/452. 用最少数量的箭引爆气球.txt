### 解题思路
先按开始坐标（结束坐标也可以）

### 代码

```cpp
bool myfunction (const vector<int>& i,const vector<int>& j) { return (i[0]<j[0]); }

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        if(n==0)return 0;

        sort(points.begin(),points.end(),myfunction);

        int res=1;
        int target=points[0][1];
        for(int i=1;i<n;++i)
        {
            if(points[i][0]>target)
            {
                target=points[i][1];
                ++res;
            }
            else
            {
                target=min(target,points[i][1]);
            }
        }

        return res;
    }
};
```