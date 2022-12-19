![360截图20191220172923566.jpg](https://pic.leetcode-cn.com/90247af1e393d68e71f250154e81443d8bcc6fedceb823131030cfa71500c645-360%E6%88%AA%E5%9B%BE20191220172923566.jpg)

```
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        //斜率公式变形： (x3-x2)(y2-y1) = (x2-x1)(y3-y2)
        return (points[2][0] - points[1][0]) * (points[1][1] - points[0][1]) != (points[1][0] - points[0][0]) * (points[2][1] - points[1][1]);
    }
};
```