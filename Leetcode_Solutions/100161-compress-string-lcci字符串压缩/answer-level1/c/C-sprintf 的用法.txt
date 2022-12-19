### 解题思路
```
sprintf(str, "%d", num);
返回值ret是写入的长度；
把num数字格式化写入到str内。
注意此处，str + n是写入的起始位置，通过这个可以从某指定位置开始写，用index记录它的索引变化
```

### 代码

```c

char* compressString(char* S){
    if (S == NULL) {
        return "";
    }

    int size = strlen(S);
    if (size <= 1) {
        return S;
    }
    char *res = (char *)malloc(sizeof(char) * size * 2);

    int index = 0;
    int nowSize = 1;

    for (int i = 0; i < size - 1; i++) {
        if (S[i] != S[i + 1]) {
            res[index++] = S[i];
            int ret = sprintf(res + index, "%d", nowSize);
            index += ret;
            nowSize = 1;
            continue;
        }
        if (S[i] == S[i + 1]) {
            nowSize++;
        }
    }

    if (nowSize >= 1) {
        res[index++] = S[size - 1];
        int ret = sprintf(res + index, "%d", nowSize);
        index += ret;
    }
    res[index] = '\0';
    int resSize = strlen(res);
    if (resSize >= size) {
        return S;
    }

    return res;
}
```