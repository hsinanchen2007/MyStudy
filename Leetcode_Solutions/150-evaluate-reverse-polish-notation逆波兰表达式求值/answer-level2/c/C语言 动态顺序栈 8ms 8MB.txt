![Snipaste_2020-04-02_20-05-01.png](https://pic.leetcode-cn.com/8e2d81f4188c4768ce97aa9201c6c96c889623793e45ed63b1bebf7c5f969905-Snipaste_2020-04-02_20-05-01.png)

### 解题思路
**核心就一个**：操作数入栈，运算符决定操作数出栈和结果入栈。

对于逆波兰表达式来说，每一个运算符的使用者都是该运算符的前两位操作数，而运算后的结果也会是一个操作数，继续入栈成为下一个运算对象。

需要注意的只有两点：
    1. 出栈的两个数，必定是最后那个出栈的数在前，先出栈的数在后，不能颠倒了运算的顺序
    2. 即便碰到的操作数会出现带有负号的情况，但对于C语言来说只需要 **`atoi`** 函数就可以解决

### 代码

```c
#define MAXSIZE 100
#define INCREASESIZE 100

/* 动态顺序栈结构 */
typedef struct stack {
    int* data;
    int top;
    int stacksize;
}Stack;

/* 入栈，栈满拓展栈空间 */
void Push(Stack* obj, int x) {
    if (obj->top == obj->stacksize - 1) {
        obj->data = (int*)realloc(obj->data, sizeof(int) * (obj->stacksize + INCREASESIZE));
        obj->stacksize += INCREASESIZE;
    }
    obj->data[++obj->top] = x;
}

/* 取栈顶的同时出栈 */
int TopAndPop(Stack* obj) {
    int x = obj->data[obj->top--];
    return x;
}

int evalRPN(char ** tokens, int tokensSize){
    Stack* obj = (Stack*)malloc(sizeof(Stack));
    obj->top = -1;
    obj->stacksize = MAXSIZE;
    obj->data = (int*)malloc(sizeof(int) * MAXSIZE);
    int x, y;
    for (int i = 0; i < tokensSize; i++) {
        //如果是运算符，取两次栈顶，计算，并将结果入栈
        if (!strcmp(tokens[i], "+")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y + x);
        }
        else if(!strcmp(tokens[i], "-")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y - x);
        }
        else if(!strcmp(tokens[i], "*")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y * x);
        }
        else if(!strcmp(tokens[i], "/")) {
            x = TopAndPop(obj); y = TopAndPop(obj);
            Push(obj, y / x);
        }
        //子字符串为操作数，将其化为整型并入栈
        else {
            Push(obj, atoi(tokens[i]));
        }
    }
    return TopAndPop(obj);   //返回最后栈的唯一一个数
}
```