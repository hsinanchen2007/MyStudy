官方题解2是将矩阵按十字分成4块矩阵，一块一块旋转。其实也可以按照剥洋葱一样一圈一圈旋转。
例如`N=4`（偶数）的时候，需要旋转两圈，第一圈如下所示：
```
***.              ...*              ....              ....
.  .   =下一项=>   .  *   =下一项=>   .  .   =下一项=>   *  .
.  .              .  *              .  .              *  .
....              ....              .***              *...
```
第二圈就如下所示
```
*.   =下一项=>   .*   =下一项=>   ..   =下一项=>   ..
..              ..              .*              *.
```
一共需要旋转的基准点是4个（3+1），和按块旋转一致。

如果N是奇数，如`N=5`时，其实也只需要旋转两圈，应为最里层那圈只有一个元素，因此不用旋转，需要选转的基准点也是6个（4+2），比块旋转的6个还要少一个。
```
****.              ....*              .....              .....
.**..              ...**              .....              *....
..x..   =下一项=>   ..x**   =下一项=>   ..x..   =下一项=>   **x..
.....              ....*              ..**.              **...
.....              .....              .****              *....
```

代码如下：
```c++
class Solution {
public:
    void rotate1cycle(vector<vector<int> >& matrix, int begin) {
        int end = matrix.size() - begin - 1;
        for (int i = 0; i < matrix.size()-begin*2-1; i++) {
            int tmp = matrix[begin][begin+i];
            matrix[begin][begin+i] = matrix[end-i][begin];
            matrix[end-i][begin] = matrix[end][end-i];
            matrix[end][end-i] = matrix[begin+i][end];
            matrix[begin+i][end] = tmp;
        }
    }

    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size()/2; i++) {
            rotate1cycle(matrix, i);
        }
    }
};
```


