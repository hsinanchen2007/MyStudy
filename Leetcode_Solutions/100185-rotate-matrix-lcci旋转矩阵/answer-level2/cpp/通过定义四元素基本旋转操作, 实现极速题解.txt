### 解题思路
首先考虑最简单的2*2矩阵的旋转操作,其本质是下标(0,0),(0,1),(1,1),(1,0)四个元素的轮换操作,即先将首元素保存,然后做后者替换前者的操作,最后将保存的首元素替换最后一个元素. 由此扩展到更大的的矩阵, 每个大矩阵可以看做多个大小不等的"环",针对每个"环"上的元素做以上定义的四元素轮换操作,即可实现整个矩阵的旋转,时间复杂度O(N^2),空间复杂度O(1),不需要额外的数组保存中间结果.

![image.png](https://pic.leetcode-cn.com/21baf373a8b258e2dab39fce813ff217720e705bb7cd34993b6814206889ae71-image.png)

### 代码

```cpp
class Solution {
public:
    void rot4element(int* a,int* b,int* c,int* d) {
        int temp = *d;
        *d = *c;
        *c = *b;
        *b = *a;
        *a = temp;
    }
    void rotate(vector<vector<int>>& matrix) {
        int side_len = matrix.size();
        int line_start = 0;
        int col_start = 0;
        while (side_len > 0) {
            for (int i = 0; i < side_len-1; ++i) {
                rot4element(&matrix[line_start][col_start+i],                         //上边长从左到右
                            &matrix[line_start+i][col_start+side_len-1],              //右变成从上到下
                            &matrix[line_start+side_len-1][col_start+side_len-i-1],   //下边长从右到左
                            &matrix[line_start+side_len-i-1][col_start]);             //左边长从下到上
            }
            line_start++;
            col_start++;
            side_len = side_len - 2;
        }
    }
};
```