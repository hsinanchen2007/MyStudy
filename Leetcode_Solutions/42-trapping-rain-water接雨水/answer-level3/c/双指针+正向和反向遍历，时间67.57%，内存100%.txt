### 解题思路
这道题直接通过字面的形状进行求解。
1.先通过两个指针不停的更新，计算单边top递增过程中，计算的雨水值；
2.只有当后面出现比top还要大的值时，才保留这部分结果；
3.反向相同处理，此处有个小坑，等最大值相同时，不累加，不然202，这两两边都相同时，会计算两遍

### 代码

```c
int trap(int* height, int heightSize){
    int sum = 0;
    int tmpSum = 0;
    int lastTop = 0;
    int top = 0;

    int i;
    /* 正向算面积 */
    for (i = 0; i < heightSize; i++) {
        if (height[i] > top) {
            top = height[i];
            sum += tmpSum;
            lastTop = top;
            tmpSum = 0;
        }
        if (height[i] <= top) {
            tmpSum += lastTop - height[i];
            // printf("i %d tmpSum = %d\n",i,tmpSum);
        }
    }
    // printf("sum is %d\n",sum);
    tmpSum = 0;
    lastTop = 0;
    top = 0;
    /* 反向算面积 */
    for (i = heightSize - 1; i >= 0; i--) {
        if (height[i] >= top) {
            top = height[i];
            sum += tmpSum;
            lastTop = top;
            tmpSum = 0;
        }
        if (height[i] < top) {
            tmpSum += lastTop - height[i];
            // printf("i %d tmpSum = %d\n",i,tmpSum);
        }
    }
    return sum;
}
```