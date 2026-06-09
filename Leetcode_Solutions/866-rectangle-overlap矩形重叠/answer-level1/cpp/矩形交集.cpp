### 解题思路
本题实际上存在数学解法，即使用中心点的横坐标/纵坐标差值与两矩形x/y方向边长和的一半进行比较。配合图形比较容易明白。
方案二的话是参考了题解中的反证法，找到不可能存在交集的条件，然后取反。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        //利用反证法，找到不可能重叠的几种情况
        if(rec2[3]<=rec1[1]||rec2[1]>=rec1[3]||
        rec2[2]<=rec1[0]||rec2[0]>=rec1[2])
         return false;
         else return true;
    }
};
```