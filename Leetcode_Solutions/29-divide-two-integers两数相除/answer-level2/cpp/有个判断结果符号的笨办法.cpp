假设之前的处理方法是`dividend`和`divisor`都取绝对值，最后需要我们判断输出结果的正负号。
因为输入是`int`型，最高位一定代表符号：所以我们`异或`一下输入，情况如下：
1. `dividend > 0` && `divisor > 0` -> 两个输入最高位都是`0`，`异或`以后是`0`，即商是正数
2. `dividend < 0` && `divisor < 0` -> 两个输入最高位都是`1`，`异或`以后是`0`，即商是正数
3. `dividend > 0` && `divisor < 0` -> 两个输入最高位分别是`1`和`0`，`异或`以后是`1`，即商是负数，这个时候变个符号
4. `dividend < 0` && `divisor > 0` -> 情况同上
在`dividend = 0` && `divisor < 0`的时候会可能出现问题，所以我们开始过滤掉这个情况就好了。

```
if(dividend == 0) return 0;

...

if((dividend ^ divisor) < 0) quotient = -quotient;

...

return quotient;
```
