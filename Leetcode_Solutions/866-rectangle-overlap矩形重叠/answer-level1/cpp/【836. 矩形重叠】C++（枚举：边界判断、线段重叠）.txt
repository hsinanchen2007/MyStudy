### 解题思路1
判断两个矩形是否重叠。
枚举四种不出现重叠的情况：`rec1[0]>=rec2[2]||
        rec1[2]<=rec2[0]||
        rec1[1]>=rec2[3]||
        rec1[3]<=rec2[1]`


### 代码

```cpp
class Solution {
    //判断矩形是否重叠
    //思路：枚举四种不重叠的情况

public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[0]>=rec2[2]||
        rec1[2]<=rec2[0]||
        rec1[1]>=rec2[3]||
        rec1[3]<=rec2[1])
            return false;
        return true;
        
    }
};
```
### 解题思路2
判断两个矩形是否重叠。
重叠问题分解为在X和Y两个维度的线段重叠问题；
```cpp
class Solution {
    //判断矩形是否重叠
    //思路：分解为x&y两个维度的线段重叠问题

public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return (min(rec1[2], rec2[2]) > max(rec1[0], rec2[0]) &&
                min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]));    
    }
};
```
