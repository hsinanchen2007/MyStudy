### 解题思路
比较最小值和最大值，如果其一的最小值大于另一个的最大值，则不相交

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0] >= rec2[2] || rec2[0] >= rec1[2]){
            return false;
        }
        if(rec1[1] >= rec2[3] || rec2[1] >= rec1[3]){
            return false;
        }
        return true;
    }
};
```