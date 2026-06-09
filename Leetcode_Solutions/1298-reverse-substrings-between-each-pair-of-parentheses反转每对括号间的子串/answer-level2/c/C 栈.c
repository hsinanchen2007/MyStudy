### 解题思路
1. 先在s原字符串上完成反转
2. 新建一个字符串存放去掉括号的结果，完成输出
3. 这里的栈是用来存放左括号的下标位置的，遇到右括号“）”就取出栈顶的左括号"("，实施反转
### 代码

```c
char * reverseParentheses(char * s){
    if(!s) return NULL;
    int len = strlen(s);
    int leftIndex[len];

    int i = 0;
    int idx = -1;
    while(s[i]){
        if(s[i] == '('){
            leftIndex[++idx] = i;//遇到"("则下标入栈
        }
        else if(s[i] == ')'){
            int left = leftIndex[idx] + 1;
            int right = i -1;
            while(left < right){
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++, right--;
            }
            idx--;
        }
        i++;//使用while循环时，别忘了更新下标
    }
    char *res = (char *)malloc((len + 1) * sizeof(char));
    memset(res, '\0', (len + 1) * sizeof(char));
    i = 0;
    int j = 0;
    while(s[i]){
        if(s[i] != '(' && s[i] != ')'){
            res[j] = s[i];
            j++;
        }
        i++;
    }
    return res;
}
```