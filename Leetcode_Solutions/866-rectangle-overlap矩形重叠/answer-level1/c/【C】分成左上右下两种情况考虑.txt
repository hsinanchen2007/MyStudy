### 解题思路
此处撰写解题思路

### 代码

```c
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    
    //只考虑矩阵2的左下角情况
    //矩阵2的左下角在矩阵1右上角上方
    if(rec2[1]>=rec1[3])
        return false;
    //矩阵2的左下角在矩阵1的右方
    if(rec2[0]>=rec1[2])
        return false;
    
    //只考虑矩阵2的右上角情况
    //矩阵2的右上角在矩阵1的左下方
    if(rec2[3]<=rec1[1])
        return false;
    //矩阵2的右上角在矩阵1的左方
    if(rec2[2]<=rec1[0])
        return false;

    return true;
}
```