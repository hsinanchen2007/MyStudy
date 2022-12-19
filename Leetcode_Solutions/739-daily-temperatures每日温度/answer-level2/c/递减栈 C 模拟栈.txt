/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct {
    int top;
    int size;
    int arr[30001];
} Stack;


void push_(Stack *stackHead, int element) {
    if (stackHead->top > (stackHead->size - 1)) {
        return ;
    }

    stackHead->arr[stackHead->top] = element;  
    stackHead->top++;   
    
}

int pop_(Stack *stackHead) {
    return stackHead->arr[--stackHead->top];
}

//递减栈，栈底是栈中最大的元素。数组元素的下标入栈
int* dailyTemperatures(int* T, int TSize, int* returnSize) 
{
    int *retArr = (int *)malloc(sizeof(int) * TSize);
    memset(retArr, 0, sizeof(int) * TSize);

    int arrSize = TSize;
    *returnSize = arrSize;

    Stack stack1 = {0};
    stack1.size = arrSize;
    stack1.top = 0;
    // 第一个数组元素的下标入栈
    push_(&stack1, 0);

    /* 依次遍历元素 */
    int j;      
    for (j = 1; j < arrSize; j++) {
        int stackTopEle = stack1.arr[stack1.top - 1]; // 栈顶元素的值，代表的是数组元素的下标
        if (T[j] > T[stackTopEle]) {
            while (T[j] > T[stackTopEle]) { // 循环遍历栈，直至栈顶元素所对应的数组元素的值大于T[j]
                retArr[stackTopEle] = j - stackTopEle;
                pop_(&stack1);
                
                if (stack1.top == 0) {
                    break;
                } 
                stackTopEle = stack1.arr[stack1.top - 1];
            }

            push_(&stack1, j); // 栈为空，将j入栈

        } else {
            push_(&stack1, j);
        }
    }

    return retArr;
}