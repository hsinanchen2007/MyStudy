![QQ截图20190715090615.png](https://pic.leetcode-cn.com/a906d8dcba321d6f51e4e07567398065b6c1acc2fa4a7a10c2c6e638a242cf67-QQ%E6%88%AA%E5%9B%BE20190715090615.png)

```
bool isValid(char * s){
    if (s == NULL || s[0] == '\0') return true;
    char *stack = (char*)malloc(strlen(s)+1); int top =0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') stack[top++] = s[i];
        else {
            if ((--top) < 0)                      return false;//先减减，让top指向栈顶元素
            if (s[i] == ')' && stack[top] != '(') return false;
            if (s[i] == ']' && stack[top] != '[') return false;
            if (s[i] == '}' && stack[top] != '{') return false;
        }
    }
    return (!top);//防止“【”这种类似情况
}
```
