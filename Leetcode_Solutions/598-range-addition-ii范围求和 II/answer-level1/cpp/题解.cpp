### 解题思路
此题的题目是给定一串ops数，求矩阵中含有的最大整数的个数。注意题目中一点，每个ops的意思是从[0,0]到[i,j]的全部元素都+1，即所有在[0,0]~[i,j]范围内的元素都+1。那求矩阵中含有的最大整数的个数，也就是求最小的[i,j]范围，在这个范围内，每次ops操作都会对这个范围内的元素+1，这样在这个范围内的所有元素都是相等的，且都是最大的。最后的解即是这个最小范围的面积。

### 代码

```cpp
class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minx = m;
        int miny = n;

        for (auto &iter : ops) {
            if (iter[0] < minx) {
                minx = iter[0];
            }
            if (iter[1] < miny) {
                miny = iter[1];
            }
        }

        return (minx) * (miny);
    }
};
```