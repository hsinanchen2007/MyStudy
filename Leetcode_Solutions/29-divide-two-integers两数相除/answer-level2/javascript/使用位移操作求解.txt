# 先说两个坑：
1. Math.abs

    在本题中取绝对值的函数要慎用，因为对于32位有符号整数来说abs(INT_MIN)是会溢出的。即-2147483648这个数，本身是INT_MIN，属于32位有符号整数范围内，但其取绝对值后的2147483648这个正整数则不在32位有符号整数范围之内。

    因此在本题“int32 only”的限制下条件，想通过**取绝对值**将除数与被除数都转化为**正整数**计算的方法是有风险的（如果dividend=INT_MIN，则Math.abs(dividend)就不对了）。

    解决方法是将被除数与除数都转化为**负整数**计算，这样只需要在最后的结果处判断结果是否溢出即可。

2. 关于溢出判断

    直接使用值域超过Int32的整数类型**在本题中**也是不合规的，如unsigned, long等等。我认为这样操作其实是绕过了题目限制。假如实际工作中，我们在处理问题时没有更大的数据类型，那么就绕不过去了。

    所以我认为只要是直接通过比较最终结果result与int_max,int_min大小的都是有问题的，比如max(min)这种，或者result>int_max, result<int_min 这种。因为题目要求只能使用32位整数类型，result只要是32位整数，那么它就不可能比int_max还大，比int_min还小，这时的校验就是失效的



# 使用位移操作计算的原理

位移操作可以模拟乘法：

如：7 \* 13 = 7 \* (8 + 4 + 1) = 7 \* 8 + 7 \* 4 + 7 \* 1

其中8,4,1分别是2的3,2,0次幂，因此

7 \* 13 = 7 << 3 + 7 << 2 + 7 << 0 , 对于本题来说，即是：

a \* x = b (暂不考虑余数)时，求x。根据上面位移运算模拟乘法的逻辑，可以把x看做一个由2的整数次幂的指数部分组成的一个数组。
如7 \* 13，则13大约可以看成是[3,2,0]。因此本题可以转化为求此数组，之后累加2的数组元素次幂即可。

# 算法

**目标：** 

a \* x = b，求x

**逻辑：** 

先寻找一个最大的y,y为2的整数次幂的指数部分，使得a << y最接近b,然后设b = b - (a << y)，继续寻找下一个y。直到所有y都计算出来之后，返回一个由上面所有y组成的数组，并累加之，即为答案。

**例子：** 3 \* x = 10

3 << 1 = 6 且 3 << 2 = 12
因12已经超过10的范围了，故y1 = 1。

然后，求 3 \* x = (10 - (3 << 1)) 即3 \* x = 4

可得y2 = 0，因为3 << 1 = 6,已经超过4了。

之后4 - (3 << 0) = 4 - 3 = 1。由于1已经小于3，不需要再继续找y3了。

故最终得出的y相关的数组为[1,0],则 x = 2^1 + 2^0 = 2 + 1 = 3（注：2^1 = 1<<1, 而在不溢出的情况下2 ^ n = 1 << n，后面不再赘述）。

# 再向前一步
从上面的例子可以看出，我们最终目的是要得到关于y的一个数组，数组中的每个y其实是2的整数次幂的指数。由于我们使用32位整数，故y最大也就是31（可以等于31，但不能等于32）。因此对于求每一个y，实际上就是求0~32之间的一个数，使得a << y 能够尽可能的接近 b。所以这里可以使用二分法，以(32,0]分别为上下限，然后计算出y的值，使得(a << y) <= b 且 (a << (y+1)) > b。如此，对于任意一个y，最多5次比较就能够找出y的值（因为32 = 2^5）。

# 未尽事宜
基本思路已经有了，除此之外还有一些边界逻辑要处理，主要有下面几个：
1. 最终的符号

    符号其实在评论里已经有人说了，我这里用的是除数被除数异或后右移31位。实际上就是取符号位，结果0表示正数，结果为1表示负数。

2. 计算a << y时，溢出了怎么办？

    假设我们现在需要计算a << t，而 a << t 实际上有可能溢出。这里我们需要保证:

    (a << t) < (1 << 31) (如果采用负数计算，则是 (a << t) > (-1 << 31), 这里为理解方便，采用正数说明)

    即a经过左移t位操作后应该比0x80000000要小，以保证不溢出。此时比较一下a < (1 << (31 - t)) 即可。如果a的值过大，说明a左移t位会溢出，则直接将t设为二分法的上限。

3. 最终结果溢出了怎么办

    最终结果溢出一般只有INT_MIN / -1 时出现。最简单处理方式是按照题目要求，直接判断除数与被除数的值，在程序一开始短路返回INT_MAX。
    而针对于上面的算法，其实就是求出的y = 31,对于y = 31的情形，根据符号短路处理即可。

4. 由于本文开头所述的Math.abs问题，需要使用负数计算。

    这里不再赘述

# 代码

```
/**
 * @param {number} dividend
 * @param {number} divisor
 * @return {number}
 */
var divide = function (dividend, divisor) {
    var INT_MAX = 0x7FFFFFFF;
    var INT_MIN = 1 << 31;

    //先判断符号
    var symbol = (dividend ^ divisor) >> 31;
    //由于Math.abs(INT_MIN)存在溢出问题
    //因此被除数与除数全部转为负数处理
    var _dividend = dividend > 0 ? -dividend : dividend;
    var _divisor = divisor > 0 ? -divisor : divisor;

    var times = divided_negtive(_dividend, _divisor);

    var output = 0;
    for (var i = 0; i < times.length; i++) {
        if (times[i] === 31) {
            //i=31表示INT_MIN，times无第二个元素，直接短路处理
            if (symbol === 0) {
                //符号为正，此时存在INT_MIN转为正数溢出,返回INT_MAX
                return INT_MAX;
            }
            return INT_MIN;
        }
        output += (1 << times[i]);
    }
    return symbol ? -output : output;

};


function divided_negtive(dividend, divisor) {
    //两负数相除
    //如-10/-20当除数小于被除数时，商为0
    if (divisor < dividend) {
        return [];
    }

    var timesMax = 32;
    var timesMin = 0;
    while (timesMax !== timesMin + 1) {
        //二分查找
        var mid = (timesMax + timesMin) >> 1;
        //divisor<<mid后有可能超过-1<<31的范围
        //因此要判断divisor是否大于等于-1<<(31-mid)，一旦小于这个值，则必定溢出
        if (divisor < (-1 << (31 - mid))) {
            //符合溢出条件，说明mid过大，将mid赋给timesMax，供下次折半查找使用
            timesMax = mid;
            continue;
        }

        var testVal = divisor << mid;
        if (testVal < dividend) {
            timesMax = mid;
        } else {
            timesMin = mid;
        }
    }
    return [timesMin].concat(divided_negtive(dividend - (divisor << timesMin), divisor));
}
```

