### 解题思路
（1）异或得到没有进位的加法结果；
（2）与运算和左移得到只有进位的加法结果；
（3）进位为0？结束加法，不为0，继续用（1）和（2）的结果做加法，因为二者相加就是结果

### 代码

```c
//递归
int getSum(int a, int b){
    if(b == 0) return a;
    int carry = ((unsigned int)(a & b)) << 1;
    int sum = a ^ b;
    return getSum(sum, carry);
}

//迭代
int getSum(int a, int b){
    int tmp = 0;
    while(b != 0) {
        tmp = ((unsigned int)(a & b)) << 1;
        a = a ^ b;
        b = tmp;
    }

    return a;
}
```