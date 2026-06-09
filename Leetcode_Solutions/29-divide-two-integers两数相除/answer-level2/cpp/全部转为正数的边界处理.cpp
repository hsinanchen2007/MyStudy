搞了一个朴素版本一提交说我超时了，好吧。本来想抄一下Luca Zhao的解法[链接在这里](https://leetcode-cn.com/problems/divide-two-integers/solution/zhi-xing-shi-jian-1msji-bai-100-by-luca-zhao/)，他是将所有数转化为负数用移位找解，代码很清晰，很容易就能看明白。

然而！leetcode的C++运行环境不支持负数移位，只能用正数了，分析一下边界处理。

将负数转化为正数时，由于INT_MIN的绝对值无法用正数表示，会溢出，需要考虑边界处理，一共有三种情况：
**1 除数是INT_MIN**
除数是INT_MIN时有两种结果：
(1) 被除数也为INT_MIN，商为1；
(2) 被除数为其他任何数，商为0，因为被除数的绝对值肯定小于INT_MIN的绝对值。

**2 被除数是INT_MIN**
被除数是INT_MIN也有两种情况：
(1) 除数为1或者-1，会产生情况3，也就是商为INT_MIN或溢出，下面再说；
(2) 因为除数为INT_MIN我们在上面已经处理了，我们想办法将被除数处理一下让它变为正数不溢出。
想到我们的朴素算法，将被除数按正负加或减上除数，然后商加1就可以了：

```c++
    if(divisor<0) dividend -= divisor;
    else dividend += divisor;
    quotient++;
```
上面的quotient是商。

**3 商是INT_MIN以及INT_MAX**
啥时候会产生INT_MIN的商：INT_MIN除以1；
啥时候会溢出（产生INT_MAX+1）：INT_MIN除以-1，这时候应该返回INT_MAX。

代码如下：

```C++
    int divide(int dividend, int divisor) {   
        //边界问题要逼疯我了，考虑三种情况：
        //（1）除数是INT_MIN
        if(divisor==INT_MIN && dividend!=INT_MIN) return 0;
        if(divisor==INT_MIN && dividend==INT_MIN) return 1;
        int quotient=0;
        //（2）被除数是INT_MIN
        //（3）商是INT_MIN以及INT_MAX
        if(dividend==INT_MIN){
            if(divisor == 1) return INT_MIN;
            if(divisor == -1) return INT_MAX;
            if(divisor<0) dividend -= divisor;
            else dividend += divisor;
            quotient++;
        }//边界处理完毕     
		bool sign=(dividend > 0) ^ (divisor > 0);
        if(dividend < 0) dividend = -dividend;
        if(divisor < 0) divisor = -divisor;
        while(dividend>=divisor){
            int temp_quo = 1;
            int temp_divisor = divisor;
            while(temp_divisor <= (INT_MAX>>1) && dividend>=(temp_divisor<<1)){
                temp_divisor = temp_divisor<<1;
                temp_quo = temp_quo<<1;
            }
            dividend -= temp_divisor;
            quotient += temp_quo;
        }
        return  sign ? -quotient : quotient;
    }
```
嗯。