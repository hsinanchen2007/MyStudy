### 解题思路
无技巧，直观的顺序查找。
用一个vector记录每一行的查找下标；
公共元素那必然要在第0行出现，所以就从第0行的下标来顺序找；以第0行下标处的值为candidate；
如果第1行后面（包括第1行）出现了比candidate大的值，或者下标已经找到头，说明没找到；第0行下标要+1再开始找；
如果在最后一行找到了candidate，则结束返回。
![图片.png](https://pic.leetcode-cn.com/7fc8842a1639e173ffc6185b8b3e702dc733a545e503f66cfea02834ade1176a-%E5%9B%BE%E7%89%87.png)


### 代码

```cpp
class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> currIdx(m, 0);
        while (currIdx[0] < n) {
            int candidate = mat[0][currIdx[0]];
            for (int i = 1; i < m; ++i) {
                bool stop = false;
                while (currIdx[i] < n) {
                    if (mat[i][currIdx[i]] < candidate) {
                        ++currIdx[i];
                    } else if (mat[i][currIdx[i]] > candidate) {
                        ++currIdx[0];
                        stop = true; // not found, search from line 0 again.
                        break;
                    } else {  // found, continue next line
                        break;
                    }
                }
                if (stop || currIdx[i] == n) {
                    break;
                }
                // found in line i
                if (i == m - 1) {
                    return candidate;
                }
            }
        }
        return -1;
    }
};
```