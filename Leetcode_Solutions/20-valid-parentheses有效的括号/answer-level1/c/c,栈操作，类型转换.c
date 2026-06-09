思路：运用栈的特点，如果碰到左括号，压入栈中，如果碰到相应的右括号，从栈中弹出，直到数组结束，如果栈为空则符合题意否则符合题意，否则不符合。这里判断是否为相应左右括号可以运用ascll编码规则，三组括号中右括号编码减左括号编码都大于0且小于3，如此判定即可。代码如下：
```C
char stack[10005];
bool isValid(char * s){
    int i;
    int len = 0;
    for(i = 0; s[i]; i++){
        if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
        	len++;
            stack[len] = s[i];
        }
        else if(s[i]==')' || s[i]==']' || s[i]=='}'){
            if((int)(s[i] - stack[len]) < 3 && (int)(s[i]-stack[len]) > 0) len--;
            else return false;
        }
    }
    if(len == 0) return true;
    else return false;
}
```