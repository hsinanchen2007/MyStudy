### 解题思路
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

示例 1:

输入: 123
输出: 321


主要考有符号的边界  范围

### 代码

```c
/*
有符号整数  -(2的31次方) ~ (2的31次方 - 1)
‬-(2的31次方) =  -2147483648 ，这个负数取正后是溢出的，超出正整数范围。
-28 % 10 = -8,  所以负数还是转成整数来计算
*/
#define MAX_INT 0x80000000

int reverse(int x){
    int a = x;
    int b = 0;
    int c = -2147483648;
    int need_rever = 0;
    //负数标记下，改为正数
    if(a < 0) {
        if(a == MAX_INT)  //这个数转成正数就溢出了，按题目要求反过来也溢出就直接返回了。
            return 0;
        a = 0 - a;
        need_rever = 1;
    }

    while(a/10){
        b = b*10 + a%10;
        a = a/10;
    }
    if(b > (MAX_INT - a)/10) //后面 b = b*10 + a，所以 b*10 + a < MAX_INT
        b = 0;
    else
        b = b*10 + a;

    if(need_rever)
        return 0-b;
    else
        return b;
}
```