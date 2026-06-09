### 解题思路
我自己也万万没有想到。。。
就这样。。。
### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec1[2] <= rec2[0] || rec1[0] >= rec2[2] || rec1[1] >= rec2[3] || rec2[1] >= rec1[3])
            return false;

        return true;
    }
};
```