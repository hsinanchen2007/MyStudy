### 解题思路
* 考虑到两个数直接交换不消耗额外的内存，使用**异或**的操作

```c++
void swap(int& x, int& y){
        x=x^y;
        y=x^y;
        x=x^y;
    }
```

>注意到，上述代码在`x`和`y`的内存地址不相等时，可以成功的执行交换，当`x`和`y`的内存地址相等时，不能成功的执行交换，此时会导致这个地址中的数被置为0

* 下面考虑矩阵的元素交换
* 原矩阵A得第i行第j列的元素为A[i][j], 经过翻转的变换得到矩阵B[n-j-1][n-i-1]
* 如何实现上面的变换?
    * 首先进行A[i][j]->C[j][i]的变换
    * 再进行C[j][i]->B[n-j-1][n-i-1]的变换
    * 这样进行如上两次变换就可以得到矩阵B，为待求矩阵,可以使用上述的`void swap()`方法了
* 时间复杂度为n*n/2-n次第一次变换的交换,$n{\times}n/2$(n为偶数)或者是$n{\times}n-n$(n为奇数).
* 空间复杂度0
### 代码

```cpp
class Solution {
public:
    void swap(int& x, int& y){
        x=x^y;
        y=x^y;
        x=x^y;
    }
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         printf("%d ",matrix[i][j]);
        //     }
        //     printf("\n");
        // }
        for(int i=0;i<n;i++){
            for(int j=0;j<n/2;j++){
                swap(matrix[i][j],matrix[i][n-j-1]);
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         printf("%d ",matrix[i][j]);
        //     }
        //     printf("\n");
        // }
    }
};
```