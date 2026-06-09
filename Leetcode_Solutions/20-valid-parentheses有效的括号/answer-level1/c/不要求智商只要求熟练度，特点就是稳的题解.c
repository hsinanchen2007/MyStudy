这种题目涉及一串序列中元素根据某种规律匹配的 
第一时间想到用栈
新元素和栈顶按照规则匹配，匹配OK出栈，不OK入栈
最后查看栈是否为空，来进行最后的判断
本题解，采用如上朴素的思路，不要弯弯绕，想到就能做出，不要求智商只要求熟练度，特点就是稳
最多就是极个别复杂用例过不了。

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 先实现栈 */
typedef struct stack_node_s {
    int val;
    struct stack_node_s *prev;
} stack_node_t;

typedef struct stack_s {
    int valid_cnt;
    stack_node_t *top;
} stack_t;

void stack_init(stack_t *stack)
{
    stack->top = NULL;
    stack->valid_cnt = 0;
}

int is_stack_empty(stack_t *stack)
{
    return (stack->top == NULL) ? 1 : 0;
}

void push_stack(stack_t *stack, int val)
{
    stack_node_t *new_node;
    stack_node_t *old_tops;

    new_node = (stack_node_t *)calloc(1, sizeof(stack_node_t));
    new_node->val = val;
    old_tops = stack->top;
    stack->top = new_node;
    new_node->prev = old_tops;
}

int pop_stack(stack_t *stack)
{
    int val;
    stack_node_t *new_tops;

    new_tops = stack->top->prev;
    val = stack->top->val;

    free(stack->top);
    stack->top = new_tops;

    return val;
}

/* () 1 -1 {} 2 -2 [] 3 -3 */
int convert_val(char c)
{
    int val;
    
    switch (c) {
    case '(' :
        val = 1;
        break;
    case ')' :
        val = -1;
        break;
    case '[' :
        val = 3;
        break;
    case ']' :
        val = -3;
        break;
    case '{' :
        val = 2;
        break;
    case '}' :
        val = -2;
        break;
    default:
        val = -9;
    }
    printf("%c to %d\n", c, val);
    return val;
}

void match_node(stack_t *stack, int new_val) 
{   int val;

    if ((is_stack_empty(stack)) || 
        ((stack->top->val + new_val) != 0)) {
        push_stack(stack, new_val);
        printf("%d push\n", new_val);
        return;
    }

    stack->valid_cnt++;
    val = pop_stack(stack);
    printf("%d make %d pop\n", new_val, val);
    
    return;
}

bool isValid(char * s)
{
    int i, len, new_val;
    stack_t stack;

    if (s[0] == '\0') {
        return 1;
    }
    
    stack_init(&stack);
    len = strlen(s);
    
    for (i = 0; i < len; i++) {
        new_val = convert_val(s[i]);
        if (new_val == -9) {
            continue;
        }
        match_node(&stack, new_val);
    }

    return is_stack_empty(&stack);
}
