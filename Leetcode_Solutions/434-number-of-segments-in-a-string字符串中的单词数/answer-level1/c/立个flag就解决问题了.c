只通过空格计数的话是不稳妥的，加一个flag标志位，当遇到非空格的字符的时候，再将返回值加一
```
int countSegments(char * s){
    int len = strlen(s);
    if(len == 0){
        return 0;
    }

    int pos = 0;
    while(s[pos] == ' '){
        if(pos == len - 1){
            return 0;
        }
        pos++;
    }

    int cnt = 0;
    int flag = 0;
    for(int i = pos; i < len; i++){
        if(s[i] == ' '){
            flag = 1;
        }
        if(flag && s[i]!=' '){
            cnt++;
            flag = 0;
        }
    }
    return cnt+1;
}

```
