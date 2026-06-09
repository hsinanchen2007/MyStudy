### 解题思路
此处撰写解题思路
本题解考虑的思路是：
1. 把括号字符串的构成转化为生成一个二叉树，字符串增加一个“（” 代表产生一个左子树，增加一个“）”代表产生一个右子树；
2. 生成二叉树的时候，要根据目标条件考虑当前节点是否有左子树和右子树的条件，即剪枝的操作
3. 对这个生成的二叉树进行中序遍历，遍历到的叶子节点就是符合条件的括号字符串。

因此本题首先实现一个迭代实现中序遍历的框架
一个栈 和 一个中序遍历的函数框架
栈的实现：
由于本题的二叉树深度其实是可知的，从第一个左括号向下一共2n个节点必然可以到达一个叶子节点，因此本题的栈就不用链表了，直接用一个2n+1的数组实现

中序遍历函数框架：
中序遍历要考虑几点：
1. 循环终止条件是：栈空 || 当前节点为NULL， 对于本题，当前节点未NULL的等价条件是
    1）**字符串中左括号的数量大于n || 右括号的数量大于左括号。这样表示该节点是个无效节点**
2. 存在左子树的条件：
    存在左子树的条件就是 字符串中左括号的数量小于等于n && 左括号的数量小于等于右括号
    这样我们就把当前节点入栈，当不满足这个条件时，我们就pop栈顶元素
框架如下：
    while ((is_stack_empty(&stack) != 1) || ((left <= n) && (left >= right))) { /* 循环条件 栈空 或者 左括号和右括号有一个小于n 这个代表还有节点未遍历到 */
        if ((left <= n) && (left >= right)) {
            push_stack(&stack, left, right);
            left++;
        } else {
            pop_stack(&stack, &left, &right);
            right++;
        }
    }
因此我们栈中肯定需要保存，当前节点左括号和右括号的数量left和right
以上我们可以保证正确做中序遍历，下面考虑我们如何记录叶子节点中输出的满足条件的字符串。
首先可以明确，最终的叶子节点的left和right的值肯定都是n，因此可以考虑在pop栈顶的时候检查下这个条件是否满足
    while ((is_stack_empty(&stack) != 1) || ((left <= n) && (left >= right))) { /* 循环条件 栈空 或者 左括号和右括号有一个小于n 这个代表还有节点未遍历到 */
        if ((left <= n) && (left >= right)) {
            push_stack(&stack, left, right);
            left++;
        } else {
            pop_stack(&stack, &left, &right);
            if ((left == n) && (right == n)) {
                //满足条件记录该叶子节点的字符串
            }
            right++;
        }
    }
然后就是考虑字符串怎么通过中序遍历节点组装起来了。
通过观察二叉树可以发现，left++ 时说明当前字符串会增加一个“（”， right++ 时增加一个“）”
遍历到最终的叶子节点时正好组装完成一个2n长的字符串，同时需要在记录叶子节点字符串的时候给字符串补上结束符
因此字符串下标**i**我们也需要存入栈中：
    left = 1;
    right = 0;
    c = '(';
    i = 0;
    while ((is_stack_empty(&stack) != 1) || ((left <= n) && (left >= right))) { /* 循环条件 栈空 或者 左括号和右括号有一个小于n 这个代表还有节点未遍历到 */
        tmp_array[i] = c;
        if ((left <= n) && (left >= right)) {
            push_stack(&stack, left, right, i);
            i++;
            left++;
            c = '(';
        } else {
            pop_stack(&stack, &left, &right, &i);
            i++;
            if ((left == n) && (right == n) && (i == 2 * n)) {
                tmp_array[i] = '\0';
                result[array_found] = (char*)calloc(1, sizeof(char) * (2 * n + 1));
                ret = strcpy(result[array_found], tmp_array);
                array_found++;
            }
            right++;
            c = ')';
        }
    }

### 代码

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int cal_max_row(int n)
{
    int val = 1;
    int i;
    
    for (i = 0; i < 2 * n - 1; i++) {
        val = val * 2;
    }

    return val;
}

/* 已使用左括号和右括号的个数 需要满足整体左（右）括号使用次数不超过n 
 * 使用右括号时 右括号的当前使用此时总小于当前已使用的左括号 存入栈 */
typedef struct stack_node_s {
    int left;
    int right;
    int i;
} stack_node_t;

typedef struct stack_s {
    int top;
    stack_node_t *stack_node;
} stack_t;

void push_stack(stack_t *stack, int left, int right, int i)
{
    stack->top++;
    stack->stack_node[stack->top].left = left;
    stack->stack_node[stack->top].right = right;
    stack->stack_node[stack->top].i = i;    
}

void pop_stack(stack_t *stack, int *left, int *right, int *i)
{
    *left = stack->stack_node[stack->top].left;
    *right = stack->stack_node[stack->top].right;
    *i = stack->stack_node[stack->top].i;
    stack->top--;
}

int is_stack_empty(stack_t *stack)
{
    return (stack->top == 0) ? 1 : 0;
}

/* 记录找到的有效串的总数 */
char ** generateParenthesis(int n, int* returnSize)
{
    char **result = NULL;
    char *tmp_array = NULL;
    int max_row = 0;
    int i;
    int left, right;
    char c;
    stack_t stack;
    char *ret;
    int array_found = 0;

    max_row = cal_max_row(n);
    result = (char **)calloc(1, sizeof(char*) * max_row);
    tmp_array = (char *)calloc(1, sizeof(char) * (2 * n + 1));
    if (n == 0) {
        tmp_array[0] = '\0';
        result[0] = (char*)calloc(1, sizeof(char) * (2 * n + 1));
        strcpy(result[0], tmp_array);
        *returnSize = 1;
        return result;
    }

    stack.top = 0;
    /* 查找树的深度最深就是2n+1 */
    stack.stack_node = (stack_node_t *)calloc(1, (2 * n + 1) * sizeof(stack_node_t));

    /* 实现二叉树的中序遍历，成功遍历到的叶子节点就是符合的字符串 */
    left = 1;
    right = 0;
    c = '(';
    i = 0;
    while ((is_stack_empty(&stack) != 1) || ((left <= n) && (left >= right))) { /* 循环条件 栈空 或者 左括号和右括号有一个小于n 这个代表还有节点未遍历到 */
        tmp_array[i] = c;
        if ((left <= n) && (left >= right)) {
            push_stack(&stack, left, right, i);
            i++;
            left++;
            c = '(';
        } else {
            pop_stack(&stack, &left, &right, &i);
            i++;
            if ((left == n) && (right == n) && (i == 2 * n)) {
                tmp_array[i] = '\0';
                result[array_found] = (char*)calloc(1, sizeof(char) * (2 * n + 1));
                ret = strcpy(result[array_found], tmp_array);
                array_found++;
            }
            right++;
            c = ')';
        }
    }
    free(tmp_array);
    *returnSize = array_found;
    return result;
}
```