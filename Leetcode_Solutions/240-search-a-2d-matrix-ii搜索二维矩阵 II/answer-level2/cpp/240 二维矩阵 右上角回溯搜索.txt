### 解题思路
![image.png](https://pic.leetcode-cn.com/16594c65dd890176439f5886adacf99442cc4daed168afa5f2ea3e3da363fe53-image.png)
从右上角开始搜索，如果
matrix[x][y] > target y = y - 1
matrix[x][y] < target x = x + 1
### 代码

```cpp
class Solution {
public:
    void find_target(int x, int y, int target, vector<vector<int>>& matrix, bool &res) {
        if (res) return;
        int m = matrix.size();
        int n = matrix[0].size();
        //cout << x << " " << y << endl;
        if (x < 0 || x >= m || y < 0 || y >= n) return;
        if (matrix[x][y] == target) {
            res = true;
            return;
        }
        if (matrix[x][y] > target) {
            find_target(x, y - 1, target, matrix, res);
        } else {
            find_target(x + 1, y, target, matrix, res);
        }
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size();
        int n = matrix[0].size();
        int x = 0;
        int y = n - 1;
        bool res = false;
        find_target(x, y, target, matrix, res);
        return res;
    }
};
```