### 解题思路
纯C 栈 快慢指针

### 代码

```c
int longestValidParentheses(char * s){
    int length = strlen(s);

    if (NULL == s || length < 2)
    {
        return 0;
    }

    int max = 0; // 快慢指针
    int slow = -1;
    int fast = 0;
    
    int* pStack = (int*)malloc(length * sizeof(int)); // 设置一个栈
    int top = -1;

    for (fast = 0; fast <= length - 1; fast++)
    {
        if (*(s + fast) == '(')
        {
            pStack[++top] = fast; // 入栈
        }
        else if (*(s + fast) == ')')
        {
            if (-1 == top) // 空栈
            {
                slow = fast;
            }
            else
            {
                top--; // 出栈

                if (-1 == top) // 空栈
                {
                    max = (fast - slow) > max ? (fast - slow) : max;
                }
                else // 栈不为空，还有未匹配的符号
                {
                    max = (fast - pStack[top]) > max ? (fast - pStack[top]) : max; // 栈顶元素
                }
            }
        }
    }

    return max;
}
```