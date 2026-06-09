![image.png](https://pic.leetcode-cn.com/b5ddf94dd7f4db880b0adb018f30906dddf08d2e7eb0ab1fb0ef7473efc83949-image.png)

主要思路再建一个同样的矩阵，走过标记1，没走过标记0；
设4个方向，每次沿着一个方向走，走到不能走(包括走到边界或者前方是‘1’墙)，转向
一直到最后连着转两次都不能继续走，退出
```
class Solution {
public:
    // 换下一个方向走
    // 0, 1 -> 1, 0 -> 0, -1 -> -1, 0 -> 0, 1 -> ...
    void change(int &a, int &b){
        if (a == 0) {
            if (b == 1) {
                a = 1;
                b = 0;
            } else {
                a = -1;
                b = 0;
            }
        } else {
            if (a == 1) {
                a = 0;
                b = -1;
            } else {
                a = 0;
                b = 1;
            }
        }
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return res;
        }
        vector<vector<int>> table(matrix);
        int lenx = matrix.size();
        int leny = matrix[0].size();
        if (lenx == 1 && leny == 1) {
            res.push_back(matrix[0][0]);
            return res;
        }
        for (int i = 0; i < lenx; i++) {
            for (int j = 0; j < leny; j++) {
                table[i][j] = 0;
            }
        }

        int a = 0;
        int b = 1;
        int x = 0;
        int y = 0;
        int flag = 0;
        res.push_back(matrix[0][0]);
        table[0][0] = 1;
        while (true) {
            if (x + a < lenx && y + b < leny && x + a >= 0 && y + b >= 0 && table[x + a][y + b] == 0) {
                flag = 0;
                x += a;
                y += b;
                res.push_back(matrix[x][y]);
                table[x][y] = 1;
                continue;
            } else {
                change(a, b);
                flag++;
                if (flag == 2) {
                    break;
                }
            }
        }  
        return res;
    }
};
```
