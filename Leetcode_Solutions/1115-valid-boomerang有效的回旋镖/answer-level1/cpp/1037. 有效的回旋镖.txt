![111.png](https://pic.leetcode-cn.com/ce86edeef9862a3af499bbb489d15ce162d1626d26abcce01bb319d45d90dcfc-111.png)
```
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        int dx1=points[1][0]-points[0][0];
        int dx2=points[1][0]-points[2][0];
        int dy1=points[1][1]-points[0][1];
        int dy2=points[1][1]-points[2][1];

        if(dx1*dy2==dx2*dy1)return false;
        return true;
    }
};
```
