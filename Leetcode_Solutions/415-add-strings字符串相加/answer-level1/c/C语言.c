### 解题思路
C语言写起来比较繁琐，主要是在算出每一位的结果后，需要反转一遍，然后根据实际长度，在串尾添加"\0"

### 代码

```c
#define MAX(a, b)  (a > b ? a : b)

char * addStrings(char * num1, char * num2){
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    char *ret = (char *)malloc(sizeof(char) * (MAX(len1, len2) + 2));
    memset(ret, 0, sizeof(char) * (MAX(len1, len2) + 1));
    int i = len1 - 1;
    int j = len2 - 1;
    int k = 0;
    int carry = 0;
    int tmp;
    
    while (i >= 0 || j >= 0) {
        int vi;
        int vj;
        if (i >= 0) {
            vi = num1[i] - '0';
        } else {
            vi = 0;
        }
        if (j >= 0) {
            vj = num2[j] - '0';
        } else {
            vj = 0;
        }
        tmp = vi + vj + carry;
        if (tmp / 10) {
            carry = 1;
        } else {
            carry = 0;
        }
        ret[k] = tmp % 10 + '0';
        i--, j--, k++;
    }
    ret[k] = tmp / 10 + '0';
    if (ret[k] == '0') {
        k--;
    }
    for (i = 0; i < (k + 1)/2; i++) {
        char tmp = ret[i];
        ret[i] = ret[k - i];
        ret[k - i] = tmp;
    }
    ret[k + 1] = '\0';
    return ret;
}
```