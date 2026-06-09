### 解题思路
直接计算出反转后的值，判断和原值是否相等（对于负数直接输出false即可）。

性能：这次我用的方法还不错，用时和内存消耗分别在前10%和20%。

【注意事项】反转后的值可能超过int的范围，比如测试样例为`2147483647`，这是此处int型的最大值，反转之后只能用long型来存储，所以编程时定义`x1`变量为long型，详情见以下注释，有两处易错点要注意。

### 代码

```c
int exponent(int count){    // 10的count次幂，常用函数
    int result = 1;
    for(int i=1;i<=count;i++){
        result *= 10;
    }
    return result;
}

bool isPalindrome(int x){
    long x1 = 0;    // 易错点，不要定义成int
    int temp = x;
    int count = 0;

    if(x<0)return false;

    while(temp!=0){
        count++;
        temp /= 10;
    }

    temp = x;
    while(count>=1){
        // printf("x1=%d\n", x1);
        x1 = x1 + (long)(temp % 10) * exponent(count-1);    // 易错点，(temp % 10)和exponent(count-1)都是int，但相乘可能超出int的范围，所以对其中一个强制类型转换
        temp /= 10;
        count--;
    }
    // printf("x1=%d\n", x1);

    return ((long)x==x1) ? true : false;

}
```