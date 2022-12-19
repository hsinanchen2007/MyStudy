除以2的次数就是二进制的位数，奇数的次数就是除最高位以外的1的个数。
例如：23 二进制即 10111，共5位，除最高位后面有3个1，所以总步数为8

代码：
```
var str = num.toString(2);
return str.length + str.replace(/0/g,"").length - 1;

```
