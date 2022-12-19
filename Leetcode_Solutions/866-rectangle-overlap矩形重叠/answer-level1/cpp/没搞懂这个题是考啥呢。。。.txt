### 解题思路
不重叠很好判断,全部列出来就完了

### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        bool a =  rec1[0]>=rec2[2]||rec1[2]<=rec2[0]||rec1[1]>=rec2[3]||rec1[3]<=rec2[1];
        return !a;

    }
};
```