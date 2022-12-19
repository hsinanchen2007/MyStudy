
![image.png](https://pic.leetcode-cn.com/35d0b5786b83073bc0037e2bcc28ed0a8ad812326e6cc3bf5a0d095ea62c6951-image.png)

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int data;
    int index;
} Stack;

int largestRectangleArea(int* heights, int heightsSize)
{
    if (heightsSize == 0) {
        return 0;
    }
    Stack *statckData = malloc(sizeof(Stack) * (heightsSize));
    int count = 0;
    int ret = 0;
    /* 数据0入栈*/
    statckData[0].data = heights[0];
    statckData[0].index = 0;
    for (int i = 1; i < heightsSize; i++) {
        while (count >= 0 && statckData[count].data > heights[i]) {
            /* 数据出栈，并计算当前顶点bar的最大值 */
            int maxValue = statckData[count].data * (i - statckData[count].index);
            if (count == 0) {
                maxValue += statckData[count].data * statckData[count].index;
            } else {
                maxValue += statckData[count].data * (statckData[count].index - statckData[count - 1].index - 1);
            }
            ret = MAX(maxValue, ret);
            count--;
        }
        /* 入栈 */
        count++;
        statckData[count].data = heights[i];
        statckData[count].index = i;
    }
    /* 计算当前剩余栈中数据的最大值 */
    while (count >= 0) {
        int maxValue = statckData[count].data * (heightsSize - statckData[count].index);
        if (count == 0) {
                maxValue += statckData[count].data * statckData[count].index;
        } else {
                maxValue += statckData[count].data * (statckData[count].index - statckData[count - 1].index - 1);
        }
        ret = MAX(maxValue, ret);
        count--;
    }
    ret = MAX(statckData[0].data * heightsSize, ret);
    free(statckData);
    return ret;
}