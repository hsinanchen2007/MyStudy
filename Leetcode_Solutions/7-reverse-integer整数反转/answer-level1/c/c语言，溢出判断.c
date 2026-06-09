### 解题思路
一开始以为是直接用printf输出结果，后来发现是return结果，果然还是没明白LeetCode的解题方式
定义一个y，保存反转后的值，但是
题目有注意，溢出返回0，用一个#include<limits.h>里面的INTMAX可以取int表示的最值，每次y要乘以10在加上最新的个位数，在这之前判断计算后是否溢出，如果溢出则返回0.
最后，如果没有溢出，计算完毕，返回y

### 代码

```c
int reverse(int x){
    int y=0;
    while(x!=0){
        if(y > INT_MAX/10 || y<INT_MAX/(-10))return 0;
        y=y*10+x%10;
        x/=10;
    }
    return y;
}
```