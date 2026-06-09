### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int a_x1 = rec1[0], a_y1 = rec1[1], a_x2 = rec1[2], a_y2 = rec1[3];
        int b_x1 = rec2[0], b_y1 = rec2[1], b_x2 = rec2[2], b_y2 = rec2[3];
        int ans = true;
        if (b_x1 >= a_x2 || b_x2 <= a_x1 || b_y1 >= a_y2 || b_y2 <= a_y1) {
            ans = false;
        }
        return ans;
    }
};
```