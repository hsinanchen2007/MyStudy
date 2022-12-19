利用数组构成栈，提交的代码含有多层嵌套，其中有两个嵌套是处理栈为空的状态。多层嵌套较难看，还需优化，优化后的代码待更。
```c
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    int i=0,stack_index=0;
    int stack[asteroidsSize];
    stack[0]=0;
    while(i<asteroidsSize){
        if(stack_index||stack[stack_index]){
            if(asteroids[i]>0)
                stack[++stack_index]=asteroids[i++];
            else{
                while(stack[stack_index]>0&&-asteroids[i]>stack[stack_index]&&stack_index) 
                    stack_index--;
                if(stack[stack_index]<0) stack[++stack_index]=asteroids[i++];
                else{
                    if(-asteroids[i]>stack[stack_index]) stack[stack_index]=asteroids[i++];
                    else if(-asteroids[i++]==stack[stack_index]){
                        if(stack_index) stack_index--;
                        else stack[0]=0;
                    }
                }
            }
        }
        else stack[stack_index]=asteroids[i++];
    }
    *returnSize=stack_index?stack_index+1:stack[0]?1:0;
    int *res=malloc(*returnSize * sizeof(int));
    for(i=0;i<*returnSize;i++) res[i]=stack[i];
    return res;
}
```