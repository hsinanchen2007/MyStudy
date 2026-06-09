### 解题思路
让我们不要俯视整个图形，让我们从Z=0的地方看xy平面。
这时，问题就转换为从是否有重叠的线段。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int rec1_x1 = rec1[0];
        int rec1_y1 = rec1[1];
        int rec1_x2 = rec1[2];
        int rec1_y2 = rec1[3];
        int rec2_x1 = rec2[0];
        int rec2_y1 = rec2[1];
        int rec2_x2 = rec2[2];
        int rec2_y2 = rec2[3];

        if (rec2_x1 >= rec1_x2 || rec2_x2 <= rec1_x1) {
            return false;
        }

        if (rec2_y1 >= rec1_y2 || rec2_y2 <= rec1_y1) {
            return false;
        }

        return true;
    }
};
```