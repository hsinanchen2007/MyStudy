### 解题思路
因为矩形是正放,所以根据题意可得 x1<x2,y1<y2。 对于另外一个矩形，也有x1’<x2',y1'<y2'，所以画一下图就可以知道矩形1和矩形2不重叠的范围

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0]>=rec2[2]||rec1[2]<=rec2[0]||rec1[1]>=rec2[3]||rec1[3]<=rec2[1]){
            return false;
        }
        return true;    
    }
};
```