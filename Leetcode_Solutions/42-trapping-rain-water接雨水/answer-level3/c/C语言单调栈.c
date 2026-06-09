### 解题思路
思路清晰，单调栈的基本用法

### 代码

```c
#include  <limits.h>
#define MaxSize    65535
typedef struct
{
    int Data[MaxSize];   // 存储元素的数组
    int topIdx;       //栈顶指针
}SeqStack;

int Push(SeqStack *L, int e)
{ // 栈已满
    if(L->topIdx==MaxSize -1)
    {
        return 0;
    }
    // 加入栈中
    L->Data[L->topIdx++] = e;
    // 返回自身
    return e;
}

// 移除栈顶元素
int Pop(SeqStack *L)
{    // 栈空
     if(L->topIdx == 0)
    {
         //返回失败
         return 0;
    }
    // 打印并返回栈
    int val = L->Data[--L->topIdx];
  //  printf("\r\n pop: %d ",val);
    return val;
}

//判断栈s是否为空
bool isEmpty(SeqStack *s)
{
    // 如果下标在0，说明栈中无元素
    if(s->topIdx != 0)
    {
        return false;
    }
    return true;
}

// 判断栈是否已满.
int isFull(SeqStack *s)
{
    // 已满返回true(1)
    if(s->topIdx != MaxSize -1)//之前的定义数组的最大值的下标
    {
        return 1;
    }
    return 0;
}

int heght_min_get(int a, int b)
{
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int trap(int* height, int heightSize){
    SeqStack wxc_stack;
    int i;
    int pop_val;
    int width;
    int bounded_height;
    int sum = 0;

    wxc_stack.topIdx = 0;
    wxc_stack.Data[wxc_stack.topIdx] = 0; /* 改用初始化栈底为第一个元素索引 */
    wxc_stack.topIdx++; /* 栈中的元素个数 */

    /* wxc_stack.Data[wxc_stack.topIdx - 1]:栈顶元素 */
    for (i = 1; i < heightSize; i++) {
        /* 栈非空，且栈顶元素小于当前高度 */
        while((isEmpty(&wxc_stack) == false) && (height[wxc_stack.Data[wxc_stack.topIdx - 1]] < height[i])) {
            pop_val = Pop(&wxc_stack);
            if (isEmpty(&wxc_stack) == true) {
                /* 发现弹栈的元素已经是栈底元素，则不用计算面积，栈底元素面积为0 */
                break;
            }
            /* 计算弹栈元素左右能夹到的雨水面积 */
            width = i - wxc_stack.Data[wxc_stack.topIdx - 1] -  1;
            bounded_height = heght_min_get(height[i], height[wxc_stack.Data[wxc_stack.topIdx - 1]]) - height[pop_val];
            sum += (width * bounded_height);
        }
        Push(&wxc_stack, i);
    }
    /*  遍历结束后，栈中剩下的元素从栈顶到栈底呈单调递增，因此无法接到雨水，不用再弹栈 */
    return sum;
}










```