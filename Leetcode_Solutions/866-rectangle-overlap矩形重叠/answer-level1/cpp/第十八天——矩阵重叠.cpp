### 解题思路

### 代码

```cpp
class Solution {
public:
 /*   bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return AxisOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) && AxisOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);
    }
    bool AxisOverlap(int x1, int x2, int x3, int x4){
        return !(x2 <= x3 || x1 >= x4);
    } */
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (!(rec1[2] <= rec2[0] || rec1[0] >= rec2[2])) && (!(rec1[3] <= rec2[1] || rec1[1] >= rec2[3]));
    }
};
```



