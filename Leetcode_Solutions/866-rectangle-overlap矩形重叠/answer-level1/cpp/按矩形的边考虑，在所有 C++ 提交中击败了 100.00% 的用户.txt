### 解题思路
按矩形的边进行判断，重合时，必定有一个矩形的至少两条边过另一个矩形内
分两种情况考虑：矩形1的边在矩形2内，矩形2的边在矩形1内。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool res = false;
        //矩形2的最右边过矩形1，并且排除矩形2的下边大于矩形1的上边 和 矩形2的上边小于矩形1的下边
        res = res || (rec2[2] > rec1[0] && rec2[2] <= rec1[2] && (!(rec2[1] >= rec1[3] || rec2[3] <= rec1[1])));
        //矩形1的最右边过矩形2，并且排除矩形1的下边大于矩形2的上边 和 矩形1的上边小于矩形2的下边
        res = res || (rec1[2] > rec2[0] && rec1[2] <= rec2[2] && (!(rec1[1] >= rec2[3] || rec1[3] <= rec2[1])));
        
        return res;
    }
};
```