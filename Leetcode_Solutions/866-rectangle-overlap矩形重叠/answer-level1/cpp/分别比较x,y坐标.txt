### 解题思路
先比较两个矩形左下角的x坐标，
如果在右侧矩形的x1坐标 ≥ 左侧矩形的x2，则必定不重叠；

同理，比较两个矩形左下角的y坐标，
如果上侧矩形的y1坐标 ≥ 下侧矩形y2，则必定不重叠；

如果两次比较都是重叠，则返回true；否则返回false。

### 代码

```cpp
class Solution {
public:
    bool isOverlap(int a,int b){
        if(b >= a)
            return false;

        return true;
    }

    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool x_res,y_res;

        x_res = rec2[0] > rec1[0] ? isOverlap(rec1[2],rec2[0]) : isOverlap(rec2[2],rec1[0]);
        if(!x_res)
            return false;

        y_res = rec2[1] > rec1[1] ? isOverlap(rec1[3],rec2[1]) : isOverlap(rec2[3],rec1[1]);

        if(x_res && y_res)
            return true;
        else
            return false;
    }
};
```