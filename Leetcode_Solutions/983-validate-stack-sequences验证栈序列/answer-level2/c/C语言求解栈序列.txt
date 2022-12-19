方法：运用动态数组构建辅助栈
思想：放入栈的每一个元素是如何出去的呢？以第一个为例，假如我第一个进去，但是我也可能第一个出去，怎么判断呢？就是每个栈中的元素都与pop栈中的top相比（这个top是指第一个输出的元素，若有元素相同那么top++），如果push栈中的元素与pop栈中的top元素不一致，那么将push栈中的元素放入，辅助栈。这时若辅助栈的元素不为空，那么就要用辅助栈的元素为下一个比较的元素，进行如下操作。依次循环。
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

    if(pushedSize == 0 || pushedSize == 1)
    {
        return true;
    }
    int top = -1, top1 = 0;
    int *stack = (int *)malloc(sizeof(int)*pushedSize);
    for(int i = 0; i < pushedSize; i++)
    {
        stack[++top] = pushed[i];
        while(top != -1 && popped[top1] == stack[top])
        {
            top--;
            top1++;
        }
    }
    if(top == -1)
        return true;
    return false;
}