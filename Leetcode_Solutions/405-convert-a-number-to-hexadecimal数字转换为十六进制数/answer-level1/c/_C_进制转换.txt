### 解题思路
分正数与负数两种情况，对于正数而言：
num / 16的商做为下一次的被除数，num / 16的余数被保留（实则为结果16进制的低位）
对于负数而言：
将num转换为补码形式，使用unsigned int表示，再进行转换，如-10，使用8bit表示为1111 0110（使用unsigned int）表示以进行转换
所以当num < 0时，使用2^32 + num(num为负数)，得到无符号的数字，再按正数进行转换。
代码如下
![123.PNG](https://pic.leetcode-cn.com/b9bad76276f8a4f6ea72b1044e61865ccba55c81f3c82434ff582703230562eb-123.PNG)


### 代码

```c
#define MAXS 64
char * toHex(int num) {
    unsigned int res, res2, m, n, i;
    char *result = NULL;
    unsigned int limit = 4294967296;
    result = (char *)malloc(sizeof(char) * MAXS);
    char letter[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    if (num < 0) {
        m = limit + num;
    } else {
        m = num;    
    }
    n = 16;
    i = 0;
    while (1) {
        res = m % n;
        res2 = m / n;
        m = res2;
        result[i++] = letter[res];
        if (res2 == 0) {
            break;
        }
    }
    int len = i / 2;
    char tmp;
    for (int j = 0; j < len; j++) {
        tmp = result[j];
        result[j] = result[i - j - 1];
        result[i - j - 1] = tmp;
    }
    result[i] = '\0';
    return result;
}
```