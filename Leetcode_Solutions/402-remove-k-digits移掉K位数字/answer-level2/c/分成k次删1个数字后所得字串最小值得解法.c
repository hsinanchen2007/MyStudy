### 解题思路
分成k次删1个数字最小值得解法
多个前后0的情况要考虑完整
### 代码

```c
void removeOnedigits(char *num){
    int len = strlen(num);
    if (len == 0) {
        return;
    }
    
    char *h = num;
    char *t = num + 1;

    for (int i = 0; i < len; i++) {
        if (t[0] == '\0') {
            h[0] = '\0';
            break;
        }

        if ((h[0] - '0') > (t[0] - '0')) { 
            memmove(h, t, len - (t - num));
            num[len - 1] = '\0';
            break;
        }

        h++;
        t++;
    }
    //去0
    h = num;
    while(h[0] == '0') {
        h++;
    }
    if (h[0] == '\0') {
        num[0] = '\0';
    } else {
        len = strlen(num);
        memmove(num, h, len - (num - h));
    }
}

char * removeKdigits(char * num, int k){
    if (num == NULL || k < 0) {
        return NULL;
    }

    if (k == 0) {
        return num;
    }
    
    for (int i = 0; i < k; i++) {
        removeOnedigits(num);
        if (num[0] == '\0') {
            break;
        }
    } 

    if (num[0] == '\0') {
        num[0] = '0';
        num[1] = '\0';
    }
    return num;
}
```