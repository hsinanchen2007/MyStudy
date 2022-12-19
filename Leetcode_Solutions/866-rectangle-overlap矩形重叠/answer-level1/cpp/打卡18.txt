### 解题思路
  首先来看，符合条件的情况，是只有这五种情况：
![image.png](https://pic.leetcode-cn.com/2738908c5b75c99e544ada698c2f0715c0e22a4fd7269c7adf2bea07bc4c7811-image.png)
  但是每种情况可以看的出来，最右边的两条边的最近那条边始终是在最左边的那两条边中的最大那条边。同理，上下边的情况也是一样。
  因此，可以得出，右上顶点中的x，y的最小值要始终大于左下点的x，y中的最大值才行，这样就可以构成重叠情况。
### 代码

```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x = (min(rec1[2] , rec2[2]) - max(rec1[0] , rec2[0]));
        int y = (min(rec1[3] , rec2[3]) - max(rec1[1] , rec2[1]));
        return x > 0 && y > 0;
    }
};
```