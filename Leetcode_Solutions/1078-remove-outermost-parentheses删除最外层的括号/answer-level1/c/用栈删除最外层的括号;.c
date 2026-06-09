### 解题思路
此处撰写解题思路

此处撰写解题思路
1 step 用栈判段是否为有效原语;
2 step count++,count--,有规律发现,最外层的'(' ')' 的count=0；
3 step 将count不为零的部份存入；
### 代码

```c
char * removeOuterParentheses(char * S){
    int count = 0 , k = 0,i=0;
   while(S[i]!='\0') {
        if(S[i] == '('){
            if(count != 0) 
            {
                S[k] = S[i];
                k++;
            }
            count++;
        }
        if(S[i] == ')'){
            count--;
            if(count != 0)
            {

             S[k] = S[i];
             k++;
            }
        }
        i++;
    }
    S[k] = '\0'; // 添加结束标志;
    return S;
}
```