### 解题思路
参考
https://leetcode-cn.com/problems/rotate-matrix-lcci/solution/c-tu-jie-yuan-di-cao-zuo-ji-bai-shuang-bai-vv-by-t/
进行矩阵移动 每次都和左上角矩阵进行交换，交换三次。
需要注意的地方是根据交换点求出待交换点的下一个坐标 [i,j]→[j,n-i-1]
然后是左上角矩阵的边界条件，当n是奇数时，左上角矩阵要加上中间的一列。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // 旋转矩阵
        int n = matrix.size();
        if(n<2) return;
        int r = n/2-1; // 行遍历边界
        int c = (n+1)/2-1; // 列遍历边界 奇偶不同。奇数时要带上中间一列的上半部分 
        for(int i=0;i<=r;i++){
            for(int j=0;j<=c;j++){
                swap(matrix[i][j],matrix[j][n-i-1]);
                swap(matrix[i][j],matrix[n-i-1][n-j-1]);
                swap(matrix[i][j],matrix[n-j-1][i]);
            }
        }
    }
};
```