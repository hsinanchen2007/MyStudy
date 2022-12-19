题目细节很多，正好复习了一下二进制的各种操作。
首先是排除几种边界条件。
**1. divisor == 1**
直接返回dividend即可。

**2. divisor == -1**
这个时候就要判断一下dividend了，如果dividend == INT32_MIN，那么取相反数肯定是溢出的，如此就返回INT32_MAX，其余情况返回-dividend。

**3. divisor == INT32_MIN**
这个时候，除非dividend == divisor时返回1，其余一律返回0。

然后就是怎么计算的问题。累加/累减法应该是首先想到的。但是这种方式遇到极限情况就容易耗时过长。比如dividend == INT32_MAX, divisor == 1的情况。

在查了一些资料后，发现二进制的除法其实可以像我们以前做的长除法，从高位到低位依次进行。比如10/3。10 = 1010b，3 = 11b。从10的最高位开始。
1. 第一位时，被除数该位为1，1b < 11b, 结果该位为0，并有模1b。
2. 第二位时，被除数该位为0，结合上一步的模1b，则为10b < 11b，结果该位为0，并有模10b。
3. 第三位时，被除数该位为1，结合上一步的模10b得101b > 11b，由于是以二进制做运算，所以结果不是0就是1。对结果该位取1，然后101b - 11b = 10b为这一步的模。
4. 第四位时，被除数该位为0，结合上一步的模10b得100b > 11b，同样，结果该位取1，100b - 11b = 1b为最后的模。那么结果就是0011b = 3。

另外举个例子，15 / 3 = 5, 1111b / 11b = 101b，按照上面的方式计算一下，你就理解了。

那么对于有一方为负数的要怎么搞呢？题目给出的范例7 / -3 = -2。显然这种方式就是看被除数的绝对值里有多少个除数的绝对值。全部转换为整数计算比较方便。事实上上面那种求商方式我也没有发现如何对负数应用。

结果的符号自然很容易确定，就不讲了。

接下来就是边界条件。尽管上面我们排除了3中边界情况，但并没有排除dividend = INT32_MIN这种情况，所以计算的时候，要考虑到它的存在。直接上一波代码，我在代码中会好好注释。
```c++
int divide(int dividend, int divisor)
{
    //排除3种边界情况
    if(divisor == 1)
    {
        return dividend;
    }
    if(divisor == -1)
    {
        if(dividend == INT32_MIN)
        {
            //这种情况下，不能返回-INT32_MIN，会溢出
            return INT32_MAX;
        }else{
            return -dividend;
        }
        
    }
    if(divisor == INT32_MIN)
    {
        if(dividend == divisor)
        {
            return 1;
        }else{
            return 0;
        }
    }
    //求结果符号
    int sign = 1;
    if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        sign = -1;
    }
    int result = 0;
    /*将dividend和divisor都转换为正数。花括号里的步骤其实就相当于取反。因为二进制求相反数就是各位取反再加1。
    这是补码。注意，之后的过程中，我们都将dividend看做一个UInt32。在不溢出的情况下，直接取反即可。但当
    dividend == INT32_MIN，它按bit表示就是0x8000 0000，而如果我们将这4个字节作为UInt32来看待，其实就是2^31 = -INT32_MIN了。
    并不需要额外的取反操作。所以，只要之后我们将dividend看做UInt32，就不会有溢出需要考虑了。只是在取反这一步需要注意这种情况。
    而由于已经排除了divisor = INT32_MIN的情况，所以它接下来也可以被放心地看做是UInt32。但题目要求只能出现Int32。因此不得不绕一点。
    */
    if(dividend < 0 && dividend > INT32_MIN)
    {
        dividend = (~dividend) + 1;
    }
    if(divisor < 0)
    {
        divisor = (~divisor) + 1;
    }
    /*由于长除法其实就是不断地移位，然后做减法和加法。但是需要注意，dividend已经被我们看做
    UInt32了。在长除法中，有个减法的过程。但对于极限情况，比如dividend = INT32_MIN，divisor = INT32 / 2 - 1的情况下，
    我们都知道结果是1，也就是长除法会进行到最后一位时才会得出结果，这个时候就有了-INT32_MIN + (INT32 / 2 - 1)的情况出现
    （因为全部取正）。这个时候得出结果肯定是溢出的，虽然并不致命，但在LeetCode的编译器中溢出就会报错，因此将一个Int32拆分成
    两个Int32，并且拆出来的部分都要作为正数。同时有另外一种情况，
    由于需要比较大小，0x8000 0000作为Int32肯定是最小的，但作为UInt32却是永远大于divisor的。*/
    int dH = (divisor >> 16) & 0x0000ffff;
    int dL = divisor & 0x0000ffff;
    int rH = 0, rL = 0;
    int remain = 0;
    for(int i = 31; i >= 0; i--)
    {
        remain = (remain << 1) | (0x01 & (dividend >> i));
        rH = (remain >> 16) & 0x0000ffff;
        rL = remain & 0x0000ffff;
        //利用高低位判断两个UInt32的大小。
        if(rH > dH || (rH == dH && rL >= dL))
        {
            /*
            为避免溢出，拆分成两个UInt32分别进行减法，低16位的减法时，被减数首先要向高16位借1从而避免出现负数的情况，借的这个1放在低16位的第16位上。由于if条件的限制，绝对不会出现
            高16位减之后出现负值的情况。高低位分别做减法之后，要先将低位的借来的1还回去，如果这个1没被用掉的话。
            */
            result = (result << 1) | 1;
            rL = (1 << 16) | rL;
            rH -= 1;
            rL -= dL;
            rH -= dH;
            rH += (rL >> 16) & 0x01;
            rL &= 0x0000ffff;
            remain = (rH << 16) | rL;
        }else{
            result <<= 1;
        }
    }
    

    if(sign == -1)
    {
        return -result;
    }

    return result;
}
```

不过在这个解法中，各种二进制操作搞得很是头疼。那么下面着重考虑一下有没有办法先把溢出的情况排除在外边。上面的解法里，已经把divisor溢出的情况排除了。这次就重点考虑一下dividend。

可以先从dividend的绝对值中去掉一个divisor的绝对值，如果操作前后dividend的符号改变了，说明dividend的绝对值是小于divisor的绝对值的，显然这种情况下结果就是0。如果没有改变，那么就接着把dividend变为正数，继续进行长除法，并且在这种情况下，由于已经预先去除了一次绝对值，所以别忘了在最后的结果中加1。在这种情况下，已经不会再出现溢出的情况了。所以完全就可以把两个数都看做Int32，正常地进行比大小、加减法即可。

```c++
int divide(int dividend, int divisor)
{
    //排除3种边界情况
    if(divisor == 1)
    {
        return dividend;
    }
    if(divisor == -1)
    {
        if(dividend == INT32_MIN)
        {
            //这种情况下，不能返回-INT32_MIN，会溢出
            return INT32_MAX;
        }else{
            return -dividend;
        }
        
    }
    if(divisor == INT32_MIN)
    {
        if(dividend == divisor)
        {
            return 1;
        }else{
            return 0;
        }
    }
    //求结果符号
    int sign = 1;
    if((dividend >= 0 && divisor < 0) || (dividend < 0 && divisor > 0))
    {
        sign = -1;
    }
    int result = 0;

    if(divisor < 0)
    {
        divisor = -divisor;
    }

    /*
    首先从被除数的绝对值中去掉一个除数的绝对值，这样之后再做转换的时候一定就不会溢出了，因此也可以放心地全程使用Int32进行加减法而不必担心溢出。
    经过这一步操作后，默认的结果已经多了一个1。因为避免这一步溢出，所以被除数仍然是带符号去进行操作的。
    */
    int tempDividend = dividend;
    if(dividend < 0)
    {
        tempDividend += divisor;
    }else{
        tempDividend -= divisor;
    }

    /*
    如果被除数在去掉除数的绝对值之后符号变化，说明被除数的绝对值小于除数的绝对值，这种情况下显然结果就是0。
    */
    if((dividend < 0 && tempDividend > 0) || (dividend > 0 && tempDividend < 0))
    {
        return 0;
    }

    if(tempDividend < 0)
    {
        tempDividend = -tempDividend;
    }
    dividend = tempDividend;

    int remain = 0;
    for(int i = 31; i >= 0; i--)
    {
        remain = (remain << 1) | (0x01 & (dividend >> i));
        
        if(remain >= divisor)
        {
            result = (result << 1) | 1;
            remain -= divisor;
        }else{
            result <<= 1;
        }
    }
    result += 1;
    if(sign == -1)
    {
        return -result;
    }
    return result;
}
```


