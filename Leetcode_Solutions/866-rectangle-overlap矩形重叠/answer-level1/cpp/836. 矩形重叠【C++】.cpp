### 解题思路

这个题我觉得主要是考思维吧，因为这个题完全没用到循环什么的，就一个两个判断就可以了，以至于我一开始都不太相信就是这么做的……

根据题目的意思，两个矩形的坐标一定是左下角坐标在前，右上角坐标在后，也就是可以确定 `rec1[0]` 不可能比 `rec1[2]` 大，其它的坐标也是同理。

首先对传入的 `rec1` 和 `rec2` 做检查，矩形坐标不合法就直接返回 `false`。

如果矩形坐标合法，那么要使两个矩形重叠，只需要满足 `rec1` 右上角的点在 `rec2` 左下角的点的右上方，`rec1` 左下角的点在 `rec2` 右上角的点的左下方。

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if (rec1.empty() || rec2.empty() ||
            rec1[0] == rec1[2] || rec1[1] == rec1[3] ||
            rec2[0] == rec2[2] || rec2[1] == rec2[3])
            return false;
        if (rec1[2] > rec2[0] && rec1[3] > rec2[1] && rec1[0] < rec2[2] && rec1[1] < rec2[3])
            return true;
        return false;
    }
};
```