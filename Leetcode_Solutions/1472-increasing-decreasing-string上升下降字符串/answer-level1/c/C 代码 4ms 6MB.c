hash映射字母表，再从低到高，从高到低取出来
第二个j++和j--的地方，怎么想都优化不掉，求指导

```


char * sortString(char * s){
    int len = strlen(s);
    char* rs = malloc(sizeof(char) * len + 1);
    int i = 0;
    int j = 0; //hash数组中的下标
    int idx = 0; //返回的字符串的下标
    int derect = 1; //方向
    int hash[26] = {0};
    for (i = 0; i < len; i++) {
        hash[s[i] - 'a']++;
    }

    for (i = 0; i < len; i++) {
        while(hash[j] == 0) {
            if (derect) {
                if (j == 25) {
                    derect = 0;
                } else {
                    j++;
                }
            } else {
                
                if (j == 0) {
                    derect = 1;
                } else {
                    j--;
                }
            }
        }

        rs[idx] = 'a' + j;
        idx++;
        hash[j]--; 
        if (derect) {
                if (j == 25) {
                    derect = 0;
                } else {
                    j++;
                }
        } else {
            if (j == 0) {
                derect = 1;
            } else {
                j--;
            }
        }
    }

    rs[len] = '\0';
    
    return rs;
}


```
