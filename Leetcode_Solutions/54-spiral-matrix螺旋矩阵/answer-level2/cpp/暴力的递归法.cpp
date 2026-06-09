### 解题思路
递归法，确定螺旋的顺序为右->下->左->上，走完一个方向就跳过走过的行/列，换个方向继续走。当走过的所有行/列都被跳过，递归结束。为了便于阅读理解，代码写得比较长。

另外发现leetcode的执行时间的统计精度好像比较粗……提交了多次，不是0ms就是4ms……

![1.png](https://pic.leetcode-cn.com/aecd8dcead9b410f5112d93e5a9e47b24d576366870901c459d530626099c779-1.png)


### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;

        int height = matrix.size(), width = 0;
        if (height > 0) {
            width = matrix[0].size();
        }

        if (height == 0 || width == 0) {
            return result;
        }

        result.push_back(matrix[0][0]);
        helper(matrix, 0, 0, 0, height-1, 0, width-1, "right", result);

        return result;
    }

private:
    void helper(vector<vector<int>>& matrix, int i, int j, //i,j为游标
            int up, int down, int left, int right, //上下左右4个边界
            string direction, vector<int> &result) { //direction为方向，右->下->左->上
        if (up > down || left > right) {
            return;
        }

        result.pop_back();

        if (direction == "right") {
            while (j <= right) {
                result.push_back(matrix[i][j]);
                j++;
            }
            //跳过上面一行，游标向下
            helper(matrix, i, j-1, up+1, down, left, right, "down", result);
        }
        if (direction == "down") {
            while (i <= down) {
                result.push_back(matrix[i][j]);
                i++;
            }
            //跳过右边一列，游标向左
            helper(matrix, i-1, j, up, down, left, right-1, "left", result);
        }
        if (direction == "left") {
            while (j >= left) {
                result.push_back(matrix[i][j]);
                j--;
            }
            //跳过下面一行，游标向上
            helper(matrix, i, j+1, up, down-1, left, right, "up", result);
        }
        if (direction == "up") {
            while (i >= up) {
                result.push_back(matrix[i][j]);
                i--;
            }
            //跳过左边一列，游标向右
            helper(matrix, i+1, j, up, down, left+1, right, "right", result);
        }

        return;
    }
};
```