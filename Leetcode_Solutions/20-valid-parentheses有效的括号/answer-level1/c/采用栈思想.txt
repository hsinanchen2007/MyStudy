### 解题思路
##### strlen 和 sizeof 区别
之前不知道这这俩者的区别
简单来说strlen(char*)函数求的是字符串的实际长度，它求得方法是从开始到遇到第一个'\0',如果你只定义没有给它赋初值，这个结果是不定的，它会从aa首地址一直找下去，直到遇到'\0'停止。 
而sizeof()返回的是变量声明后所占的内存数，不是实际长度。
##### 思路
1. 建立一个跟字符串一样长的字符串作为栈
2. 设定一个栈顶元素
3. 从字符串第一个字符读到最后一个
4. 如果读到的是左括号则入栈；
5. 如果是右括号则检查栈顶元素是否与其匹配，如果不匹配返回false，如果匹配则栈顶元素出栈。
6. 考虑特殊情况，字符串为空或者字符串不存在，返回true。

### 代码

```c
bool isValid(char * s){

    if (s==NULL || strlen(s)<=0) return true;
    int top = 0;
    char *stack = (char*)malloc(strlen(s)+1);
    for (int i = 0; i<strlen(s); i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            stack[top++] = s[i];
        }else{
            if(--top < 0) return false;
            if(s[i]==')' && stack[top] != '(') return false;
            if(s[i]=='}' && stack[top] != '{') return false;
            if(s[i]==']' && stack[top] != '[') return false;
        }
    }
    if (top > 0) return false;
    return true;
}
```