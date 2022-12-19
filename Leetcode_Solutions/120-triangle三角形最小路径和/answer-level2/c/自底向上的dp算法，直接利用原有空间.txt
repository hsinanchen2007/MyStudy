### 解题思路
从倒数第二行开始计算每个数字到下一个节点的最小值并加上当前节点值存入当前节点，最后triangle[0][0]中存储的就是最终的最短路径结果。

### 代码

```c
#define min(a,b) (a<b?a:b)

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    int i,j;
    if(triangle == NULL) return 0;
//自底向上
    for(i = triangleSize-2;i >= 0;i--){
        for(j = 0;j < triangleColSize[i];j++ ){
            triangle[i][j] = min(triangle[i+1][j],triangle[i+1][j+1])+triangle[i][j];
        }
    }
    return triangle[0][0];
}
```