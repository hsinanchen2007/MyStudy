```
// 字符串翻转函数
void swapstr(char * s, int begin, int end) 
{
    int i = begin;
    int j = end;
    while (i<j) {
        if (s[i] == '(') {
            i++;
        }
        if (s[j] == ')') {
            j--;
        }
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
    return;
}

char * reverseParentheses(char * s){
    int len = strlen(s);
    if (len == 0) {
        return NULL;
    }
    len++;
    char *ans = NULL;
    ans = (char *)malloc(len*sizeof(char));
    memset(ans, '\0', len*sizeof(char));
    int beginnum = 0;
    int i = 0;
    int begin[1000] = { 0 };
    for (i = 0; i < len; i++) {
        // 保存所有的左括号
        if (s[i] == '(') {
            begin[beginnum++] = i;
        } else if (s[i] == ')') {
            // 翻转最近左括号和当前右括号之间的字符串
            swapstr(s, begin[--beginnum], i);
            printf("22:%s\n", s); 
        }
    }
    int anslen = 0;
    // 剔除括号的正式数据
    for (i = 0; i < len; i++) {
        if(s[i] == '(' || s[i] == ')') {
            continue;
        }
        ans[anslen++] = s[i];
    }
    printf("33:%s\n", ans);
    return ans;
}

```