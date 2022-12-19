### 解题思路
此处撰写解题思路
处撰写解题思路
考虑第二个矩形的左下角位置，只有四种情况下可以出现重叠，考虑四种情况就可以解决
### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        if(rec2[0]<=rec1[0] &&rec2[1]<=rec1[1])
        {
            if(rec2[2]>rec1[0] && rec2[3]>rec1[1])
            {
                return 1;
            }
        }
        if(rec2[0]<=rec1[0] && rec2[1]>=rec1[1] && rec2[1]<rec1[3])
        {
            if(rec2[2]>rec1[0])
            {
                return 1;
            }
        }
        if(rec2[0]>=rec1[0] &&rec2[1]<=rec1[1] && rec2[0]<rec1[2])
        {
            if(rec2[3]>rec1[1])
            {
                return 1;
            }
        }
        if(rec2[0]>=rec1[0] && rec2[0]<rec1[2])
        {
            if(rec2[1]>=rec1[1] && rec2[1]<rec1[3])
            {
                return 1;
            }
        }

        return 0;
    }
};
```