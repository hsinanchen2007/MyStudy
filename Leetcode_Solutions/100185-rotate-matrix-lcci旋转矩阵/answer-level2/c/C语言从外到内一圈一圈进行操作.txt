### 解题思路

外层for循环控制遍历圈数，最外圈，次外圈，...，最里圈。
内层for循环在一条边上遍历点数，每个点与本圈另外3条边上的3个点交换值。

每圈index+1，step-2。
index是每圈左上角那个点的坐标(index,index)。
step是每圈一条边上需要遍历的点数(index,index),(index,index+1),...(index,index+step)。
然后这里每个点都和其外3边上对应的点交换值。比如6*6的矩阵。第2圈
(1,1),(4,1),(4,4),(1,4)交换
(1,2),(3,1),(4,3),(2,4)交换
(1,3),(2,1),(4,2),(3,4)交换

### 代码

```c
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int k, step, index, temp;
    for(step=matrixSize-1, index=0; step>0; step-=2, index++){
        for(k=0; k<step; k++){
            temp = matrix[index][index+k];
            matrix[index][index+k] = matrix[index+step-k][index];
            matrix[index+step-k][index] = matrix[index+step][index+step-k];
            matrix[index+step][index+step-k] = matrix[index+k][index+step];
            matrix[index+k][index+step] = temp;
        }
    }
}
```