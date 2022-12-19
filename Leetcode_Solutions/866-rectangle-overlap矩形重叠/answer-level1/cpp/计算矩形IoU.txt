### 解题思路
计算矩形IoU,其实可以分解为两个步骤:
1.计算两个矩形水平方向上线条的交集
2.计算两个矩形竖直方向上线条的交集
### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x_low=max(rec1[0],rec2[0]);
        int x_high=min(rec1[2],rec2[2]);

        int y_low=max(rec1[1],rec2[1]);
        int y_high=min(rec1[3],rec2[3]);

        return x_high>x_low && y_high>y_low;
    }
};
```