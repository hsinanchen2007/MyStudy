中间注释掉的语句是我的思考过程
```
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){

    if(/*pushedSize != poppedSize || */pushedSize==0)
        return true;
    int Stack[pushedSize];
    int top = -1, poppedNum = 0;//top为Stack的顶，poppedNum为popped数组的头
    int i;
    for(i = 0; i < pushedSize;i++){
        Stack[++top] = pushed[i];    //将pushed数组的一个数读入栈中
        while(top != -1 && Stack[top]==popped[poppedNum]){//将栈顶与 popped数组的top对比
            top--;
            // if(poppedNum != poppedSize)
                popped++;
        }//如果相同，栈 pop，popped数组 top+1
    }
    if(-1 == top)
        return true;
    return false;
    //如果push完了，无法将栈 pop完，则为不合法，否则为合法
}
```
