### 解题思路
* 不重叠条件：rect1 位于 rect2 的左侧、或右侧、或上侧、或下侧；
* 重叠条件：与x轴平行的边，存在重叠，而且与y轴平行的边也存在重叠。

### 代码
* 不重叠条件
```cpp
class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return !(rec1[0] >= rec2[2] || rec2[0] >= rec1[2] ||
             rec1[1] >= rec2[3] || rec2[1] >= rec1[3]);
    }
};
```
![3.2.png](https://pic.leetcode-cn.com/6943416254c0e35f054a350b43e3b6ed52e9a286fdc8133d59a690057ba4379d-3.2.png)

* 重叠条件
```cpp
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        return min(rec1[2], rec2[2]) > max(rec1[0], rec2[0])
                && min(rec1[3], rec2[3]) > max(rec1[1], rec2[1]);
    }
```
![3.1.png](https://pic.leetcode-cn.com/010792e7d9fcbe78afa676e338b29cac4af4d66f1d2eca9db7fdf56f0a29f68a-3.1.png)
