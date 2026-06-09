### 解题思路
C语言，模拟二进制加法，注意返回值是指针，所以需要动态申请内存

### 代码

```c
char * addBinary(char * a, char * b){
    int alen = strlen(a);
    int blen = strlen(b);
    if (alen == 0) {
        return b;
    }
    if (blen == 0) {
        return a;
    }
    int len = (alen > blen ? alen + 1 : blen + 1);
    char *result = (char *)malloc(sizeof(char) * (len + 1));
    char ma[len + 1];
    char mb[len + 1];
    //初始化数组
    memset(result, '0', sizeof(char) * (len + 1));

    //将a和b倒序，方便进位
    for (int i = 0; i < alen / 2; i++) {
        char tmp = a[i];
        a[i] = a[alen - 1 - i];
        a[alen - 1 - i] = tmp;
    }
    for (int i = 0; i < blen / 2; i++) {
        char tmp = b[i];
        b[i] = b[blen - 1 - i];
        b[blen - 1 - i] = tmp;
    }
    for (int i = 0; i < len; i++) {
        if (i < alen) {
            ma[i] = a[i];
        } else {
            ma[i] = '0';
        }
    }
    for (int i = 0; i < len; i++) {
        if (i < blen) {
            mb[i] = b[i];
        } else {
            mb[i] = '0';
        }
    }
    //开始相加
    for (int i = 0; i < len; i++) {
        if (ma[i] == '0' && mb[i] == '0') {
            if (result[i] == '0') {
                result[i] = '0';
            } else {
                result[i] = '1';
            }
        }
        if (ma[i] == '0' && mb[i] == '1') {
            if (result[i] == '0') {
                result[i] = '1';
            } else {
                result[i] = '0';
                result[i + 1] = result[i + 1] + 1;
            }
        }
        if (ma[i] == '1' && mb[i] == '0') {
            if (result[i] == '0') {
                result[i] = '1';
            } else {
                result[i] = '0';
                result[i + 1] = result[i + 1] + 1;
            }
        }
        if (ma[i] == '1' && mb[i] == '1') {
            if (result[i] == '0') {
                result[i] = '0';
                result[i + 1] = result[i + 1] + 1;
            } else {
                result[i] = '1';
                result[i + 1] = result[i + 1] + 1;
            }
        }
    }
    //确定实际长度
    if (result[len - 1] == '1') {
        len = len;
    } else {
        len = len - 1;
    }
    //结果倒回去
    for (int i = 0; i < len / 2; i++) {
        char tmp = result[i];
        result[i] = result[len - 1 - i];
        result[len - 1 - i] = tmp;
    }
    result[len] = '\0';
    return result;
}
```