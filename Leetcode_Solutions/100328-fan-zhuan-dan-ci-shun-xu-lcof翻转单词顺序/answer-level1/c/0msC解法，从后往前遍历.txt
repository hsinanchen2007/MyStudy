```
#define Max 0xffff
char* reverseWords(char* s){
    int re = 0,flag = 0,index,i,j;    //flag标记单词的开始或结束
    char *res = malloc(Max);
    index = strlen(s) - 1;

    while(index >= 0){
        if(s[index] != ' ' && !flag){            
            j = index;                 //后指针指向单词尾字符
            flag = 1;
        }
        if((s[index] == ' '  || index == 0) && flag){   
            i = (index == 0 && s[index] != ' ') ? index : index + 1; //前指针指向单词首字符或非空的首字符
            while(j >= i){
                res[re++] = s[i++];
            }
            res[re++] = ' ';
            flag = 0;
        }
        index--;

    }
    if(re == 0){ return ""; }
    res[--re] = '\0';
    return res;
}
```
