```
int str_to_int(char *s, int n) {
    int ret = 0;
    int i = 0;
    for (i = 0; i < n; i++) {
        ret = 10 * ret ;
        ret += (s[i] - '0');
    }
    return ret;
}

bool ischar(char a) {
    return (a >= 'a') && (a <= 'z');
}

bool isdigital(char a) {
    return (a >= '0') && (a <= '9');
}
bool validWordAbbreviation(char * word, char * abbr){
    int abbr_start = 0;
    int word_start = 0;
    int wlen = strlen(word);
    int alen = strlen(abbr);
    bool find = true;

    while(1) {
        if (ischar(abbr[abbr_start])) {
            if(abbr[abbr_start] != word[word_start]) {
                find = false;
                break;
            } else {
                abbr_start++;
                word_start++;
            }
        } else if (isdigital(abbr[abbr_start])) {
                if(abbr[abbr_start] == '0') {
                    find = false;
                    break;
                }
                int len = 0;
                while (abbr_start < alen && isdigital(abbr[abbr_start])) {
                    len++;
                    abbr_start++;
                }
                int num = str_to_int(&abbr[abbr_start-len],len);
                word_start += num;
                //printf("%d\n", num);
        }
        if ((word_start >= wlen) || (abbr_start >= alen)) {
            break;
        }
    }
    
    if ((abbr_start == alen) && (word_start == wlen)) {
        return true;
    } else {
        return false;
    }
}
```

几个异常分支处理：
1. 注意数字首数字是'0'的场景；
2. 注意多位数字的处理。
