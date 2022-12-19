### 解题思路
一开始对库函数不熟悉，将num转成数字以后，先转成16进制字符串，然后再判断并返回。
看了其他大佬的方法，用sprintf就可以直接将数字转成想要的进制的字符串。
还得加强对C标准库的学习

### 代码

```c
#define N 12
void numToHex(long n, char *str) {
    int count = 0;
    while(n / 16) {
        int tmp = n % 16;
        if (tmp >= 0 && tmp <= 9) {
            str[count++] = tmp + '0';
        } else {
            str[count++] = tmp - 10 + 'A';
        }
        n /= 16;
    }
    str[count++] = (n >= 0 && n <= 9) ? n + '0' : n - 10 + 'A';
    for (int i = 0; i < count / 2; i++) {
        char tmp = str[i];
        str[i] = str[count - 1 - i];
        str[count - 1 - i] = tmp;
    }
    str[count] = 0;
}
char * toHexspeak(char * num){
    long n;
    char *res = calloc(N, sizeof(char));
    sscanf(num, "%ld", &n);

//    numToHex(n, res);
    sprintf(res, "%lX", n);
    for (int i = 0; i < strlen(res); i++) {
        if (res[i] > '1' && res[i] < '9') {
            return "ERROR";
        }
        if (res[i] == '0'){
            res[i] = 'O';
        }
        if (res[i] == '1'){
            res[i] = 'I';
        }
    }
    return res;
}

```