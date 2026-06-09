### 解题思路
1.hash先获取各字符的个数；
2.使用双指针遍历，当大于1/4的均满足后，获取窗口大小；
3.往后滑动窗口；

### 代码

```c
int balancedString(char * s){
    int hash[4] = {0};
    char *tmp = s;
    while (*tmp) {
        switch (*tmp) {
        case 'Q':
            hash[0]++;
            break;
        case 'W':
            hash[1]++;
            break;
        case 'E':
            hash[2]++;
            break;
        case 'R':
            hash[3]++;
            break;
        }
        tmp++;
    }
    int i;
    int tm = 0;
    for (i = 0; i < 4; i++) {
        hash[i] -= strlen(s) / 4;
        if (hash[i] != 0)
            tm = 1;
    }
    if (tm == 0)
            return 0;

    int result = strlen(s);
    int tmpRet = 0;
    char *hand = s;
    char *tail = s;
    while (*hand || *tail) {
       
        if (*hand && (hash[0] > 0 || hash[1] > 0 || hash[2] > 0 || hash[3] > 0)) {
             if (*hand == 'Q')
                hash[0]--;
            if (*hand == 'W')
                hash[1]--;
            if (*hand == 'E')
                hash[2]--;
            if (*hand == 'R')
                hash[3]--;
            tmpRet++;
        //    printf("tmpret %d\n",tmpRet);
            hand++;
        }
       //  printf("hand %c Q %d W %d E %d R %d\n",*hand, hash[0], hash[1],hash[2], hash[3]);
        if (hash[0] <= 0 && hash[1] <= 0 && hash[2] <= 0 && hash[3] <=0) {
        //    printf("hash[0] %d tail %c \n",hash[0],*tail);
            if (result > tmpRet)
                result = tmpRet;
            if (*tail == 'Q')
                hash[0]++;
            if (*tail == 'W')
                hash[1]++;
            if (*tail == 'E')
                hash[2]++;
            if (*tail == 'R')
                hash[3]++;
            tail++;
            tmpRet--;
        } else if (!*hand) {
            tail++;
        }
    }
    return result;
     
}
```