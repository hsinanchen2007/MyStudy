### 解题思路
参照84题解法，以第一列为纵轴，每一行分别为横轴，是不是和84题要求的东西一模一样？
每一行分别输入，调用84题接口即可。
![image.png](https://pic.leetcode-cn.com/0d24edeb4adf3e7af6d69c3d5bca7e2c88ea07289b512788d657903ad11ca523-image.png)


### 代码

```c
typedef struct
{
    int index;
    int val;
}Temp;
int largestRectangleArea(int* heights, int heightsSize){
    //int* ret = (int*)malloc(sizeof(int) * heightsSize);
    if(!heightsSize) {
        return 0;
    }
    Temp* stack = (Temp*)malloc(sizeof(Temp) * heightsSize);
    int i;
    int max = 0;
    int h, l;
    int top = -1;

    for(i = 0; i < heightsSize; i++) {
        while(top > -1 && heights[i] <= stack[top].val) {
            int h = stack[top].val;
            top--;
            l = top == -1 ? -1 : stack[top].index;
            max = fmax(max, h * (i - l - 1));
        }
        top++;
        stack[top].val = heights[i];
        stack[top].index = i;
    }

    int idx = stack[top].index;
    while(top > 0) {
        h = stack[top].val; 
        top--;      
        max = fmax(max, h * (idx - stack[top].index));
    }
    max = fmax(max, stack[top].val * heightsSize);

    return max;
}

int maximalRectangle(char** matrix, int matrixSize, int* matrixColSize){
    if(matrixSize == 0) {
        return 0;
    }
    int* height = (int*)malloc(sizeof(int) * (*matrixColSize));
    int ret = 0;
    int i, j;
    for(j = 0; j < (*matrixColSize); j++) {
        height[j] = 0;
    }
    
    for(i = 0; i < matrixSize; i++) {
        for(j = 0; j < (*matrixColSize); j++) {
            if(matrix[i][j] == '0') {
                height[j] = 0;
            } else {
                height[j]++;
            }
        }
        ret = fmax(ret, largestRectangleArea(height, *matrixColSize));
    }
    return ret;
}
```