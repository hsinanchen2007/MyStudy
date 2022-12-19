![image.png](https://pic.leetcode-cn.com/b0b2487d5b09e053cc7061a6d67978d40fe330627a69a1c7adae013f897fd12c-image.png)

```
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        long long width = (long long)rec1[2] - (long long)rec1[0] + (long long)rec2[2] - (long long)rec2[0];
        long long height = (long long)rec1[3] - (long long)rec1[1] + (long long)rec2[3] - (long long)rec2[1];
        long long width_1 = max((long long)rec2[2], (long long)rec1[2]) - min((long long)rec2[0], (long long)rec1[0]);
        long long height_1 = max((long long)rec2[3], (long long)rec1[3]) - min((long long)rec2[1], (long long)rec1[1]);
        return (width - width_1 > 0 ? width - width_1 : 0) > 0 &&
                   (height - height_1 > 0 ? height - height_1 : 0) > 0;
    }
};
```
