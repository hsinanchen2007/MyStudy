### 解题思路
螺旋矩阵前进路径分为：向右、向下、向左、向上。
输入二维矩阵非空时，一定是当前路径前进到终点才需要判断是否全部走完。
可以对4种路径分别进行循环，设置变量top、right、down、left记录走过的行、列数。

### 代码

```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> dst;
        if (matrix.empty()) return dst; 
        //一定要将判断是否为空输入写在前面，因为输入为空时，下面语句是错误的
        const int m = matrix.size();   //row
        const int n = matrix[0].size();   //coloum
        int i = 0, j = 0, l = 0, top = 0, down = 0, left = 0, right = 0;
        dst.push_back(matrix[i][j]); //将第一个值代入
        while(l < m * n){
            //在同一行，不停往右走
            while (j < n - 1 - right){
                ++j;
                ++l;
                dst.push_back(matrix[i][j]);
            }
            if (l == m * n - 1) return dst; //到达行末判断是否结束螺旋
            top += 1;
            //在同一列，不停往下走
            while (i < m - 1 - down){
                ++i;
                ++l;
                dst.push_back(matrix[i][j]);
            }
            if (l == m * n - 1) return dst; //到达列末判断是否结束螺旋
            right += 1;
            //在同一行，不停往左走
            while (j > left){
                --j;
                ++l;
                dst.push_back(matrix[i][j]);
            }
            if (l == m * n - 1) return dst;
            down += 1;
            //在同一列，不停往上走
            while (i > top){
                --i;
                ++l;
                dst.push_back(matrix[i][j]);
            }
            if (l == m * n - 1) return dst;
            left += 1;
        }
        return dst;        
    }
};
```