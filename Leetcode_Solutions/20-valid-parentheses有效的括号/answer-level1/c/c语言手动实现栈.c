### 解题思路
此处撰写解题思路
c语言没有stack的库，只能手动实现了。当然val也可以动态生成，根据s的长度来申请内存。
### 代码

```c


typedef struct{
    char val[65535];
    int num;
}stack_t;

stack_t stack;

void push(char c)
{
    stack.val[stack.num++] = c;
}

int is_empty()
{
    return !(stack.num);
}

char pop()
{
    if(is_empty())
        return '\0';

    stack.num--;
    return stack.val[stack.num];
}

int is_left(char c)
{
    switch(c){
        case '{':
        case '(':
        case '[':
            return 1;
        default:
            return 0;
    }
}

bool isValid(char * s){
    int i = 0;
    char c;
    memset(&stack, 0, sizeof(stack_t));

    if(NULL == s)
        return true;

    for(i = 0; i < strlen(s); i++)
    {
        if(is_left(s[i]))
        {
            push(s[i]);
        }
        else
        {
            c = pop();
            switch(s[i]){
                case ')' :
                    if('(' != c)
                        return 0;
                    break;
                case '}':
                    if('{' != c)
                        return 0;
                    break;
                case ']':
                    if('[' != c)
                        return 0;
                    break;   
            }
        }
    }

    return is_empty();
}
```