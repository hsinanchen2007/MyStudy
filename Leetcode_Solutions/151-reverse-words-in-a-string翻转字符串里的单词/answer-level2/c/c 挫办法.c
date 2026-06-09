### 解题思路
方法比较挫，优化空间比较大

### 代码

```c
char * reverseWords(char * s){
    
    if(strlen(s) == 0)
        return s;
    if(strlen(s) == 1 && s[0] == ' ') {
        s = "";
        return s;
    }        
    
    int kong = 1;
    for (int i = 0; i < strlen(s); i++) {
        if(s[i] != ' ') {
            kong = 0;
        }
    }
    if(kong == 1) {
        s = "";
        return s;
    }

    char * tmpstr = (char*)malloc(sizeof(char)*(strlen(s) + 1));
    memset(tmpstr, 0, strlen(s) + 1);
    for (int i = 0; i < strlen(s); i++) {
        tmpstr[i] = s[strlen(s) - i - 1];
    }

    char * res = (char*)malloc(sizeof(char)*(strlen(tmpstr) + 1));
    memset(res, 0, strlen(tmpstr) + 1);
    int i = 0;
    if(tmpstr[i] == ' ') {
        do {
            i++;
        }while(tmpstr[i] == ' ');
    }
    
    int j = 0;
    if(tmpstr[strlen(tmpstr) - 1] == ' ') {
        if (strlen(tmpstr) == 2) {
            tmpstr[strlen(tmpstr) - 1] = '\0';
            return tmpstr;
        }
        j = strlen(tmpstr) - 1;
        do {
            j--;
        }while(tmpstr[j] == ' ');
    }

    if(j == 0) 
       memcpy(res, (const char *)(tmpstr + i), strlen(tmpstr) + 1 - i - j);
    else 
       memcpy(res, (const char *)(tmpstr + i), j - i + 1);
    
    i = 0;
    while(i <= strlen(res)) {
        if(res[i] == ' ' && res[i + 1] == ' ') {
            int k = i;
            do {
                res[k] = res[k + 1];
                k++;
            }while(k <= strlen(res));
            i = 0;
            continue;
        }
        i++;
    }

    if(strlen(res) == 1) {
        return res;
    }        

    char tmp = '\0';
    int begin = 0;
    int end = 0;
    int flag = 0;
    int pos = 0;
    for (int i = 0; i <= strlen(res); i++) {
        if(res[i] == ' ' || res[i] == '\0') {
            end = i - 1;
            pos = end;
            for (int j = begin; j < end; j++) {
                tmp = res[pos - j + begin];
                res[pos - j + begin] = res[j];
                res[j] = tmp;
                end--;
            }
            flag = 0;
            begin = 0;
        } else {
            if(flag == 0)
            {
                begin = i;
            }
            flag++;
        }
    }    
    return res;
}
