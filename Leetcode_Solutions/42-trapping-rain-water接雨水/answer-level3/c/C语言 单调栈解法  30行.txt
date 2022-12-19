```
int trap(int* height, int heightSize)
{
    if (heightSize <= 2) {
        return 0;
    }
    int sum = 0;
    int cnt = 0;
    int *stack = calloc(heightSize, sizeof(int));
    for (int i = 0; i < heightSize; i++) {
        if ((cnt == 0) && (height[i] == 0)) {
            continue;
        }
        if ((cnt == 0) || (height[i] < stack[0])) {
            stack[cnt++] = height[i];
            continue;
        }
        while (cnt > 0) {
            sum += stack[0] - stack[--cnt];
        }
        stack[cnt++] = height[i];
    }
    int max = 0;
    while (cnt > 0) { /* 所有元素访问完栈内还有元素，一直出栈并计算, max为右边有效高度 */
        if (stack[cnt - 1] < max) {
            sum += max - stack[cnt - 1];
        } else {
            max = stack[cnt - 1];
        }
        cnt--;
    }
    free(stack);
    return sum;
}
```
