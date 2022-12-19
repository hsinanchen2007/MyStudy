### 解题思路
可以利用栈。具体思路见注释
### 代码

```c
typedef struct
{
    int data[10000];
    int top;
}Stack;
int Push(Stack *S,int data){
    if(S->top == 10000 - 1){
        return -1;
    }
    S->top++;
    S->data[S->top] = data;
    return 1;
}
int Pop(Stack *S,int *data){
    if(S->top == 0){
        return -1;
    }
    *data = S->data[S->top];
    S->top--;
    return 1;
}
int GetTop(Stack *S){

    return(S->data[S->top]);
}
int IsEmpty(Stack *S){
    return(S->top == 0);
}
void ClearStack(Stack *S){
    for(int i = 0;i < 10000; i++){
        S->data[i] = 0;
    }
    S->top = 0;
}
int trap(int* height, int heightSize){
    int i = 0;
    int imax,max;
    imax = 0;
    max = 0;
    Stack S;
    ClearStack(&S);
    int water = 0;
    while(i < heightSize){
        if(height[i] > max){
            max = height[i];
            imax = i;
        }
        i++;
    } // 找到最大值和最大值的下标
    printf("max is %d,imax is %d,water is %d; ",max,imax,water);
    for(int i = 0;i < imax;i++){
        if(height[i] > GetTop(&S)){
            Push(&S,height[i]);
        } else {
            water += (GetTop(&S) - height[i]);
        }
    } // 最大值的左侧，当前柱子高于栈顶的柱子，入栈，否则可以接水，接水的单位数等于和当前栈顶柱子
    // 的高度差
    // 最大值的右侧，和左侧类似。
    printf("max is %d,imax is %d,water is %d; ",max,imax,water);
    ClearStack(&S);
    for(int i = heightSize -1;i >= imax;i--){
        if(height[i] > GetTop(&S)){
            Push(&S,height[i]);
        } else {
            water += (GetTop(&S) - height[i]);
        }
    }
    printf("max is %d,imax is %d,water is %d; ",max,imax,water);
    return water;
}
```