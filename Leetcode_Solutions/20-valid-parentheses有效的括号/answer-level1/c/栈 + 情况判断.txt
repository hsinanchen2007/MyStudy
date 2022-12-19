![image.png](https://pic.leetcode-cn.com/97b8bb6df1ca119b0a8ce042d475e780f719a4291e71e03ef7b2ce57c606240c-image.png)

首先判断字符串长度的情况。
题目中说空字符串判断为有效，可直接返回true。
如果长度为奇数，显然无效，返回false。

之后使用switch case语句。
如果传入左括号，则入栈。
如果传入右括号，首先判断是否为第一个元素（否则stack[top-1]语句段错误）。如果不是，则看上一个元素是否为对应的左括号，如果是则top元素出栈。如果传入其他字符，可直接返回false。

for循环结束后，检查top位置，如果未清零，说明有剩余的左括号。返回false。

```
bool isValid(char * s){
    int l = strlen(s);
    if(l==0)
        return true;
    if(l%2)
        return false;
    int top = 0;
    int* stack = (int*)malloc(l * sizeof(int));
    for(int i = 0;i < l;i++){
        switch(s[i]){
            case('('): stack[top++] = s[i];break;
            case('{'): stack[top++] = s[i];break;
            case('['): stack[top++] = s[i];break;
            case(')'):if(top == 0)  return false;
                    else if(stack[top-1] == '(') {top--; break;}
                    else  return false;
            case('}'):if(top == 0)  return false;
                    else if(stack[top-1] == '{') {top--; break;}
                    else  return false;
            case(']'):if(top == 0)  return false;
                    else if(stack[top-1] == '[') {top--; break;}
                    else  return false;
            default: return false;
        }
    }
    if(top > 0)
        return false;
    return true;
}
```
