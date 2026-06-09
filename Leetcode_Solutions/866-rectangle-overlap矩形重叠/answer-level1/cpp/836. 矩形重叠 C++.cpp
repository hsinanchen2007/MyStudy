### 解题思路

列出不重叠的情况：
rec2.at(0) >= rec1.at(2)  矩形2在矩形1的右侧
rec2.at(2) <= rec1.at(0)  矩形2在矩形1的左侧
rec2.at(1) >= rec1.at(3)  矩形2在矩形1的上面
rec2.at(3) <= rec1.at(1)  矩形2在矩形1的下面

其他情况都是重叠的


### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        return !(rec2.at(0) >= rec1.at(2) || rec2.at(2) <= rec1.at(0) ||  rec2.at(1) >= rec1.at(3) || rec2.at(3) <= rec1.at(1));
    }
};
```