方法一：数据量不大，直接暴力记录每轮的状态，状态不再变化时结束。
方法二：先从左往右推，遇到L再局部从右往左推。
代码：
```
char * pushDominoes(char * dominoes){
    int len = strlen(dominoes);
    if (len == 0) {
        return "";
    }
    int count;
    char* arr = (char*)malloc((len + 1) * sizeof(char));
    memcpy(arr, dominoes, (len + 1) * sizeof(char));
    while (1) {
        count = 0;   
        memcpy(dominoes, arr, (len + 1) * sizeof(char));
        for (int i = 0; i < len; i++) {
            if (dominoes[i] != '.') {
                continue;
            }
            if (i == 0) {
                if (dominoes[1] == 'L') {
                    arr[0] = 'L';
                    count++;
                }
                continue;
            }
            if (i == len - 1) {
                if (dominoes[len - 2] == 'R') {
                    arr[len - 1] = 'R';
                    count++;
                }
                continue;
            }
            if (dominoes[i - 1] == 'R' && dominoes[i + 1] != 'L') {
                arr[i] = 'R';
                count++;
            } else if (dominoes[i + 1] == 'L' && dominoes[i - 1] != 'R') {
                arr[i] = 'L';
                count++;
            }
        }
        if (count == 0) {
            break;
        }
    }
    return dominoes;
}
```
方法二：
```
char * pushDominoes(char * dominoes){
    int len = strlen(dominoes);
    if (len == 0) {
        return "";
    }
    int r = -1;
    int l = -1;
    for (int i = 0; i < len; i++) {
        if (dominoes[i] == 'L') {
            if (r < 0) {
                for (int j = l + 1; j < i; j++) {
                    dominoes[j] = 'L';
                }
            } else {
                for (int j = (i + r) / 2 + 1; j < i; j++) {
                    dominoes[j] = 'L';
                }
                if ((i + r) % 2 == 0) {
                    dominoes[(i + r) / 2] = '.';
                }
                r = -1;
            }
            l = i;
        } else if (dominoes[i] == 'R') {
            r = i;
        } else {
            if (r >= 0) {
                dominoes[i] = 'R';
            }
        }
    }
    return dominoes;
}
```

