### 解题思路
递减栈的应用，分两步
1、依次遍历原数组的元素，将没有比其大的元素入栈
2、当栈里还有剩余元素时，从给定数组的开始位置开始，找出比栈顶大的元素。

### 代码

```c

#define STK_VOLUME 10001
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int top; // top 指向下一个往栈里写入的位置
    int size; // 栈可以存储元素的最大个数
    int arr[STK_VOLUME];
} Stack;


void push_(Stack *stackHead, int element) {
    if (stackHead->top > (stackHead->size - 1)) {
        return ;
    }

    stackHead->arr[stackHead->top] = element;  
    stackHead->top++;

}

int pop_(Stack *stackHead) {
    if (stackHead->top > 0) {
        --stackHead->top;
        return stackHead->arr[stackHead->top];
    }
    
    return -1;
}

void InitStack(Stack *stackHead, int stksize) 
{
    stackHead->top = 0;
    stackHead->size = stksize;
    memset(stackHead->arr, 0, sizeof(int) * STK_VOLUME);
}

Stack g_stack = {0};

//int *g_result = NULL;

// 当栈里有元素时，因为栈是递减的，所以从原数组的起始位置开始遍历元素，依次找到比栈顶对应元素大的元素
void DealStackRemain(int* nums, int numsSize, int **retIn)
{
    int i = 0;
    int top;
    if (g_stack.top > 0) {
        top = g_stack.top;
            while((top > 0) && (i < numsSize)) {
                while ((top > 0) && (nums[i] > nums[g_stack.arr[top - 1]])) {
                    (*retIn)[g_stack.arr[top - 1]] = nums[i];
                    top--;
                }
                i++;
            }
    }
}

void Proc_(int* nums, int numsSize, int* returnSize, int **retIn)
{
    int i;
    int stkTopEle;
    int *ret = *retIn;

    for (i = 1; i < numsSize; i++) {
        if (g_stack.top > 0) {
            stkTopEle = g_stack.arr[g_stack.top - 1];
            if (nums[stkTopEle] < nums[i]) {
                while (nums[stkTopEle] < nums[i]) { //栈顶元素小于nums[i]时出栈，直到栈顶对应数组中的元素大于nums[i]为止
                    stkTopEle = pop_(&g_stack);
                    ret[stkTopEle] = nums[i];

                    if (g_stack.top == 0) {
                        break;
                    }
                    stkTopEle = g_stack.arr[g_stack.top - 1];
                }

                // 当栈为空 或 栈顶对应数组中的元素大于nums[i]时，把索引i压栈
                push_(&g_stack, i);
            } else {
                // 索引入栈
                push_(&g_stack, i);
            }
        }
    }

    DealStackRemain(nums, numsSize, retIn);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize)
{
    if (nums == NULL || returnSize == NULL) {
        return NULL;
    }

    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int *g_result = (int *)malloc(sizeof(int) * numsSize);
    if (g_result == NULL) {
        return NULL;
    }
    memset(g_result, -1, sizeof(int) * numsSize);
    
    *returnSize = numsSize;

    if (numsSize == 1) {
        g_result[0] = -1;
        return g_result;
    }

    InitStack(&g_stack, numsSize);
    // 第一个数组元素的下标入栈
    push_(&g_stack, 0);

    Proc_(nums, numsSize, returnSize, &g_result);

    for (int j = 0; j < numsSize; j++) {
        printf("%d ", g_result[j]);
    }
    return g_result;

}
```