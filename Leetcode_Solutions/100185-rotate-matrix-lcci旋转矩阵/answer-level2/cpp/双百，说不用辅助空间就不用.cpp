### 解题思路
主要就是利用swap完成交换，寻找规律

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 0 || n == 1) return; //如果只有一行或没有元素，直接返回
        for (int i = 0; i < n / 2; i++) {  //超过n/2部分不用再旋转了，否则会出错
            for (int j = i; j < n - i - 1; j++) {   //确定旋转边界
                int left = i, right = n - i - 1, down = n - i - 1;
                swap(matrix[i][j], matrix[j][right]); 
                swap(matrix[i][j], matrix[down][n - j - 1]);
                swap(matrix[i][j], matrix[n - j - 1][left]);
                /*
                    可以试着自行旋转试下：(每次i,j位置与后面位置交换)
                        1.a b c d->b a c d
                        2.b a c d->c a b d
                        3.c a b d->d a b c
                */
            }
        }
        return;
    }
};
```