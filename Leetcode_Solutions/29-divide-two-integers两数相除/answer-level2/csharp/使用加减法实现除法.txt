### 解题思路
最简单的方法，循环每次dividend-divisor，不过算法效率非常差。我下面这种方法，最多需要减31次即可算出结果。
1、先处理溢出的情况：-2147483648/-1=2147483648，但是int能存储的最大值是2147483647，这种情况直接返回2147483647
2、为了避免后面的divisor相加可能出现的溢出，先将dividend、divisor转换成负数，当然要先存好结果的符号
3、定义两个栈，用来存储中间产生的divisor相加的结果，以及该结果除以divisor的值（divisor的倍率）
4、若dividend小于等于divisor（因为转换成负数来处理，相当于正数的dividend大于等于divisor），就将divisor入栈，同时divisor的倍率也入栈，如果dividend的小于等于两倍的divisor（注意不能用加法，可能会溢出，转换成减法来处理，就是代码里面d1-d2<=d2），那么将divisor翻倍，倍率也翻倍，继续入栈，循环以上操作，直到dividend<=dividend*2^n
5、现在我们的栈里面已经有了从大到小的2^n*divisor，只需要一个一个从栈里面弹出来进行减操作，同时结果ret+=存在栈里的倍率，直到d1<divisor
6、好了，现在我们得到一个正数的结果值，最后就处理一下结果值的符号就大功告成了

###

```csharp
public class Solution {
    public int Divide(int dividend, int divisor) {
        if (divisor == 0) return 0;
        if (dividend == int.MinValue && divisor == -1) return int.MaxValue;
        bool isNegative = (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);
        dividend = dividend < 0 ? dividend : -dividend;
        divisor = divisor < 0 ? divisor : -divisor;
        int ret = 0;
        int addCount = 1;
        int d1 = dividend, d2 = divisor;
        Stack<int> d2Stack = new Stack<int>();
        Stack<int> addStack = new Stack<int>();
        while (d1 <= d2) {
            d2Stack.Push(d2);
            addStack.Push(addCount);
            if (d1 - d2 <= d2) {
                d2 += d2;
                addCount += addCount;
            }
            else break;
        }
        while (d1 <= divisor) {
            d2 = d2Stack.Pop();
            addCount = addStack.Pop();
            if (d1 <= d2) {
                ret += addCount;
                d1 -= d2;
            }
        }
        return isNegative ? -ret : ret;
    }
}
```