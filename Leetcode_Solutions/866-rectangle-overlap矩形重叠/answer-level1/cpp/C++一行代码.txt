### 解题思路
此处撰写解题思路
这个是非常典型的检测bounding box重合率计算
方法直接参考代码，其实不难
### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1.empty() || rec2.empty())
            return false;
        if (min(rec1[2], rec2[2]) - max(rec1[0], rec2[0]) > 0 && min(rec1[3], rec2[3]) - max(rec1[1], rec2[1]) > 0)
            return true;
        return false;
    }
};
```