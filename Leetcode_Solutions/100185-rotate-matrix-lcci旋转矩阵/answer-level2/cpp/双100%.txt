### 解题思路
顺时针旋转， 关键在于for 循环的变量控制， 外层for 表示层数， 内层for 表示移动的个数。 可以考虑从斜对角开始，次数j=i
![image.png](https://pic.leetcode-cn.com/e18cb25b2ca6d40ef6b843f69c6f25ced0aef4cb933bb16398a702f1a8449311-image.png)

### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int N = matrix.size();
        for(int i = 0; i< N/2; i++)
        {
            for(int j= i;j< N - 1 - i;j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[N-1-j][i];
                matrix[N-1-j][i] = matrix[N-1-i][N-1-j];
                matrix[N-1-i][N-1-j] = matrix[j][N-1-i];
                matrix[j][N-1-i] = tmp;
            }
        }
        return;
    }
};
```