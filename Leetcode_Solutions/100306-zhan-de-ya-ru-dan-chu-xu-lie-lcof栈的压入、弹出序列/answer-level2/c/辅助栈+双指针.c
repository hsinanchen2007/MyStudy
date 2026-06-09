# 辅助栈+双指针
```c
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    if(!pushed||!popped) return false;
    int temp[1000];
    int popind = 0;
    int pushind = 0;
    for(int i = 0; i<poppedSize;i++)
    {
        
        temp[pushind++] = pushed[i];
        while(pushind>0&&temp[pushind-1]==popped[popind])
        {
            pushind--;
            popind++;
        }
    }
    return pushind==0;
}
```