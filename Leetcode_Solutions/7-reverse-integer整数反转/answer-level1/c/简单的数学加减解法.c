### 解题思路
使用数学方法进行进栈，依次从后将数字填入rev中，之后输出rev即可。

由于题目中，数值范围为 [−2^31,  2^31 − 1]，
而，2的31次方为 2,147,483,648，
因此控制溢出
需保证最后加法时的rev = rev*10 + pop小于该整数：
所以，rev为正数时，rev<INTMAX/10，或rev == INTMAX/10时，pop小于7
负数时，pop大于-8

### 代码

```c
#include <math.h>
int reverse(int x){
    const int INTMAX= pow(2,31);

    int pop,rev = 0;

    //使用计算，一步一步进行栈活动
    while(x!=0){
        //pop
        pop = x%10;
        x=x/10;//剩下数字
        //push in stack
        if(rev>INTMAX/10 || (rev == INTMAX/10 && pop>7)) return 0;
        if(rev<(-INTMAX/10) || (rev == (-INTMAX/10) && pop<-7)) return 0;
        rev = rev*10 + pop;
    }
    return rev;
}
```