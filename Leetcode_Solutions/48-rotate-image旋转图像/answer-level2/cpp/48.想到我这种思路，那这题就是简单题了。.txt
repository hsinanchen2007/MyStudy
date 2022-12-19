### 解题思路
这种题以后就这么做，**先上下交换，再斜着交换，就ok了**。
换一种说法：先以图像以水平方向上的对称轴为轴进行翻转，再以主对角线为轴进行翻转
不要问为什么，这种题就这么做。
有收获求点赞。
### 代码

```cpp
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if(n<2) return ;
        for(int i=0; i<n/2; i++){ // 上下翻转
            for(int j=0; j<n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[n-1-i][j];
                matrix[n-1-i][j] = tmp;
            }
        }
        for(int i=0; i<n-1; i++){ // 以主对角线为轴进行翻转
            for(int j=i+1; j<n; j++){
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};
```
