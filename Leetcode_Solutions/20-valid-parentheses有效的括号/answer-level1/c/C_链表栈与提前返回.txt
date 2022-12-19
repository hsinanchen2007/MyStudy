### 解题思路
看了那么多写的动态数组栈，我来补充一个链表栈，链表栈理论无限长（有内存溢出可能）。可以在返回前设置`isempty=true`栈内有元素就返回假即可。

### 遍历完再看栈是否空
```c []
typedef struct StackNode{
    char data;
    struct StackNode *next;
} LinkStack, *stack_ptr;

bool ismatch(char first, char second) {
    if (second - first == 1 || second - first == 2) return true;
    return false;
}

void push(stack_ptr *stack, char bracket) {
    stack_ptr node = (stack_ptr)malloc(sizeof(LinkStack));
    node->data = bracket;
    node->next = *stack;  // 交换头结点
    *stack = node;  // 改变头结点
}

void pop(stack_ptr *stack) {
    if (*stack) {  // 不空
        stack_ptr q = *stack;  // q暂存删除结点
        *stack = (*stack)->next;
        free(q);  // 删除结点
    }else return;
}

void destroy(stack_ptr *stack) {
    stack_ptr tmp;
    while (*stack) {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

bool isValid(char * s){
    /* 1.初始化链表栈 */
    stack_ptr stack = NULL;
    /* 2.准备添加元素 */
    while (*s != '\0') {
        if (stack && ismatch(stack->data, *s)) {
            pop(&stack);  // 传入二级指针
            s++;  // 字符移动
        }else push(&stack, *s++);
    }
    bool res = !stack;
    destroy(&stack);
    return res;
}
```

### 提前返回

+ 1.左右:[):一定错误
+ 2.左左:[{:还可以继续
+ 3.右左:}[:除非右先入栈,否者不可能
+ 4.右右:)]:同上一样，都是不可能出现的，直接错误
就是在入栈之前，如果当前bracket与栈顶不匹配，且是右bracket！直接返回。  

- 1.栈不空，且无处让栈顶元素出栈(两者不匹配)，只需要看入栈是否是左括号，否者返回假。
- 2.栈空，入栈必须是左括号，否者直接假
- 3.只含有`[`的栈！坑，最终需要判断栈是否为空返回结果
### 代码
```c []
typedef struct StackNode{
    char data;
    struct StackNode *next;
} LinkStack, *stack_ptr;

bool ismatch(char first, char second) {
    if (second - first == 1 || second - first == 2) return true;
    return false;
}

bool isleft(char c) {
    if (c == 40 || c == 91 || c == 123) return true;  // 左
    return false;  // 右
}

void push(stack_ptr *stack, char backet) {  // 传入二级指针修改栈顶链表
    stack_ptr node = (stack_ptr)malloc(sizeof(LinkStack));
    node->data = backet;
    node->next = *stack;  // 交换头结点
    *stack = node;  // 改变头结点
}

void pop(stack_ptr *stack) {
    if (*stack) {  // 不空
        stack_ptr q = *stack;  // q暂存删除结点
        *stack = (*stack)->next;
        free(q);  // 删除结点
    }else return;
}

void destroy(stack_ptr *stack) {
    stack_ptr tmp;
    while (*stack) {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

bool isValid(char * s){
    /* 1.初始化链表栈 */
    stack_ptr stack = NULL;
    /* 2.准备添加元素 */
    while (*s != '\0') {
        if (stack && ismatch(stack->data, *s)) {
            pop(&stack);  // 传入二级指针
            s++;  // 字符移动
        }else if (isleft(*s)) push(&stack, *s++);
        else return false;
    }
    bool res = !stack;
    destroy(&stack);
    return res;
}
```

### 数组栈与字典映射
```c []
bool isValid(char *s) {
    int len = strlen(s), top = 0;
    if (len & 1) return false;  // 奇数

    char left_brackets[128] = {0};
    left_brackets[40] = 41;left_brackets[91] = 93;left_brackets[123] = 125;
    char *stack = (char *)malloc(sizeof(char) * (len / 2 + 1));  // 一定要多1

    while (*s) {
        if (left_brackets[*s]) stack[top++] = *s++;
        else if(!top || left_brackets[stack[--top]] != *s) return false;
        else s++;  // 左括号但不匹配s移动
    }
    free(stack);
    return !top;  // top是否为0
```
