### 解题思路
官方思路

### 代码

```c
bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int stack[pushedSize+1];
    int stack_top = -1;
    int stack_size = 0;
    int pop_index = 0;
    for(int i=0;i<pushedSize;i++){
        stack[++stack_top] = pushed[i];
        stack_size++;
        while(stack_size > 0 && pop_index < poppedSize && stack[stack_top] == popped[pop_index] ){
            stack_top--;
            stack_size--;
            pop_index++;
        }
    }
    return pop_index == poppedSize;


}
```