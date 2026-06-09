![QQ截图20190724091927.png](https://pic.leetcode-cn.com/c883da467587af4fbf526662c0478881803c566b9e26f71259f911aba3130abb-QQ%E6%88%AA%E5%9B%BE20190724091927.png)

```
int char_num[128]; //用来记录text中每个字母的数量
int exist[128];    //用来标识该字母是否已经入栈
char* stack = NULL;//用来当作栈
char * smallestSubsequence(char * text){
    if (text == NULL || text[0] == '\0')                  return text;
    for (int i = 'a'; i < 123; ++i)                       char_num[i] = exist[i] = 0;
    for (int i = 0; text[i]; ++i)                       ++char_num[text[i]];
    if ((stack = (int *)calloc(64, sizeof(int))) == NULL) return NULL;
    int top = 0;                                         //上面为初始化

    for (int i = 0; text[i]; ++i) {
        --char_num[text[i]];
        if (exist[text[i]]) continue; //已经入栈
        if ( top && (stack[top-1] > text[i]) && (char_num[stack[top-1]]) ) {//后面还有该字符
            exist[stack[--top]] = 0;  //出栈
            ++char_num[text[i--]];
        }else{
            exist[text[i]] = 1;
            stack[top++] = text[i];   //入栈
        }
    }
    stack[top] = '\0';
    return stack;
}

```
