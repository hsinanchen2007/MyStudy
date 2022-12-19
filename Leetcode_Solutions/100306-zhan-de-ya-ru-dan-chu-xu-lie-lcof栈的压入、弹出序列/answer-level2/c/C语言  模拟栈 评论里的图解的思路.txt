### 解题思路
自己模拟压栈，且边压栈边和出栈的比较

### 代码

```c

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    if(pushedSize!=poppedSize) return false;
    int *stack=(int*)calloc(1000,sizeof(int));
    int k=0;
    int i=0;
    int j=0;
    for(i=0;i<pushedSize;i++)
    {
        stack[k++]=pushed[i];  //模拟压栈     
        while(( (k>0) && (stack[k-1]==popped[j]) && j<poppedSize)) // 且边压栈边匹配 ，匹配成功说明满足弹栈
        {
            k--;//把匹配的pop出去   
            j++; //找下一个出栈的           
        }
    }
    return k==0 ? true:false;  //模拟栈中的数被匹配完，即正确
}
```