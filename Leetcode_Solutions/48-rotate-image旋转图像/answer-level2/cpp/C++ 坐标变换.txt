### 解题思路
![image.png](https://pic.leetcode-cn.com/4da2add9be2616fe868da107d20bbaea1af4150a749e226eb9838e5c0c2de71d-image.png)

将原图像分为四个区，类似于四个象限的区域，我们旋转其中一个象限，然后就可以实现旋转整个图像。
j_tmp 为 jj 点的源，i_tmp 为 ii 的源。

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix)
    {
        int len = matrix.size();
        for(int i = 0; i <= (len - 1) / 2; i++)
        {
            for(int j = 0; j < len / 2; j++)
            {
                int i_tmp,j_tmp,ii = i,jj = j,tmp = matrix[i][j];
                do
                {
                    i_tmp = -(jj - len + 1);
                    j_tmp = ii;
                    matrix[ii][jj] = matrix[i_tmp][j_tmp];
                    ii = i_tmp;
                    jj = j_tmp;
                } while (i_tmp != i || j_tmp != j);
                matrix[j][-i+len-1] = tmp;
            }
        }
    }
};
```