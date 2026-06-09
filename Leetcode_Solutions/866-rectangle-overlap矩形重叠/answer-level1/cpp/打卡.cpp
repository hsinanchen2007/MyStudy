### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //左右边界判断

        if (rec1[2] <= rec2[0]) return false;
        if (rec2[2] <= rec1[0]) return false;
        //上下边界判断
        if (rec1[3] <= rec2[1]) return false;
        if (rec2[3] <= rec1[1]) return false;

        return true;
    }
};
```