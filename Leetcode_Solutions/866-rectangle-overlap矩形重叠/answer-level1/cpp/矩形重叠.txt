### 解题思路
第一种：考虑没有重叠时的条件
第二种：x、y轴投影重叠
自己做的时候踩坑：考虑了重叠的情况，比较复杂，应考虑没有重叠时的条件

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {   
        if(rec1[2]<=rec2[0]||rec1[0]>=rec2[2]||rec1[1]>=rec2[3]||(rec1[3]<=rec2[1])){
            return false;
        }
        return true;
    }
};
//第二种(参考了官方)
class Solution {
    public boolean isRectangleOverlap(int[] rec1, int[] rec2) {
        return (Math.min(rec1[2], rec2[2]) > Math.max(rec1[0], rec2[0]) &&
                Math.min(rec1[3], rec2[3]) > Math.max(rec1[1], rec2[1]));
    }


```