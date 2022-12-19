### 解题思路
考虑反例，假如两个矩形不重叠，需要满足什么条件？
1. 两个矩形的横坐标范围没有重叠
2. 两个矩形的纵坐标范围没有重叠
上面两个情况满足其一即可，因此重叠的情况就是 !(1 || 2)

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        /* 0 --> Left
        * 2 --> Right
        * 1 --> Low
        * 3 --> High*/
        return !(rec1[2] <= rec2[0] || rec1[0] >= rec2[2]) && !(rec1[3] <= rec2[1] || rec1[1] >= rec2[3]);
    }
};
```