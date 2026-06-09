&emsp;&emsp;题目中要求*对角线*，我想到“**化斜为直**”的办法（有些奇葩），就是第一层不动，下一层总在上一层的位置上左移一格，最后呈现阶梯状，将这个矩阵用0补全，与原矩阵相比，行不变，列变成了原来的行与列的和。针对每一列，找到要排序的边界，进行原地快排，代码如下：
```
class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int maxRow = mat.size();
        int maxCol = mat[0].size();
        vector<vector<int>> c(maxRow, vector<int>(maxRow + maxCol, 0));
        vector<vector<int>> res;
        int ord = maxRow + 1;
        // 矩阵变形
        for(int i = 0; i < maxRow; ++i) {
            int temp = --ord;
            for(int j = 0; j < maxCol; ++j) {
                c[i][temp] = mat[i][j];
                temp++;
            }
        }
        // 找到边界, 进行快排
        for(int i = 0; i < c[0].size(); ++i) {
            int j = 0;
            int k = maxRow - 1;
            for(; j < maxRow; ++j) {
                if(c[j][i] > 0) break;
            }
            for(; k >= 0; --k) {
                if(c[k][i] > 0) break;
            }
            quickSort(j, k, c, i);
        }
        // 矩阵还原
        for(int i = 0; i < maxRow; ++i) {
            vector<int> t;
            for(int j = 0; j < c[0].size(); ++j) {
                if(c[i][j] > 0) t.push_back(c[i][j]);
            }
            res.push_back(t);
        }
        return res;
    }

    void quickSort(int left, int right, vector<vector<int>>& c, int i) {
        if(left >= right) return;
        int j, k, base, tem;
        j = left, k = right;
        base = c[left][i];
        while(j < k) {
            while(c[k][i] >= base && j < k) k--;
            while(c[j][i] <= base && j < k) j++;
            if(j < k) {
                tem = c[j][i];
                c[j][i] = c[k][i];
                c[k][i] = tem;
            }
        }
        c[left][i] = c[j][i];
        c[j][i] = base;
        quickSort(left, j - 1, c, i);
        quickSort(j + 1, right, c, i);
    }
};
```
&emsp;&emsp;总结：用时12ms，空间11.6MB，效率一般，程序太长，思路易懂。
