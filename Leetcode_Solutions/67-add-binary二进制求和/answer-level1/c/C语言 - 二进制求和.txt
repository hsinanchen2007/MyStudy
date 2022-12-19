### 解题思路
    跟着C++大佬们学习，写出优美的code ~ ~ ~
### 代码

```c
#define N 1000
char * addBinary(char * a, char * b){
    int len1 = strlen(a),len2 = strlen(b),carry = 0,k = 0;
    int i,j;
    char *c = (char *)malloc(sizeof(char)*N);
    //核心代码，从右往左进行运算
    for(i = len1 - 1,j = len2 - 1;i >= 0 || j >= 0 || carry;--i,--j){
        //很可能有a,b数组长度不等的时候，所以会有i,j小于0的情况，这时直接把该位置为0即可
        int x = i < 0 ? 0 : a[i] - '0';
        int y = j < 0 ? 0 : b[j] - '0';

        int sum = (x + y + carry) % 2;  //存入数组中的值

        carry = (x + y + carry) / 2;    //进位
        c[k++] = sum + '0';
    }
    c[k] = '\0';    //结束字符

    //翻转字符串
    for(i = 0,j = k - 1;i < j;i++,j--){
        char cc = c[i];
        c[i] = c[j];
        c[j] = cc;
    }
    return c;
}
```