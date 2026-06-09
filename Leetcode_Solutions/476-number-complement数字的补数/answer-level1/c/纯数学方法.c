### 解题思路
1、先求出对应数的二进制位数
2、求出2的n次幂
3、再求出补码

### 代码

```c
int findComplement(int num){
    long n = (long)(log2(num) + 1);

    n = (int)pow(2, n);
    n = n - 1 - num;

    return n;
}
```