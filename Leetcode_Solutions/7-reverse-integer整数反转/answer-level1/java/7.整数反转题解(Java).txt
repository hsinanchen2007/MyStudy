int的范围：[-2147483648,2147483647],即[-2^31,2^31-1]
long的范围：[-9223372036854775808, 9223372036854775807],即[-2^63,2^63-1]

**解法一**

1.转换成字符串(如果是负数先把负号去掉)
2.逆序查找非0数的位置
3.逆置
4.去0->如果是负数，前面加上负号->转换成数字
5.根据限定范围输出
废了老大劲......
```
public int reverse(int x) {
	// 将数字转换成字符串
	StringBuffer num = null;
	if (x < 0) {
		num = new StringBuffer(Integer.toString(x).substring(1));
	} else {
		num = new StringBuffer(Integer.toString(x));
	}

	// 逆序查找第一个非0数的位置
	int i = num.length();
	for (; i >0 && num.charAt(--i) == '0'; );
			
	//反转
	num = num.reverse();

	//1.去0
	//2.负数加负号
	long rst = Long.parseLong((x < 0 ? "-" : "") + num.substring(num.length() - (i + 1)));
			
	//转换后的数值在范围内返回该数值，否者返回0
	return (rst < -2147483648 || rst > 2147483647) ? 0 : (int)rst;
}
```

**解法二**
参照了诸位大佬的题解，果然我太菜了。
```
public int reverse(int x) {
    long res = 0;
    while (x != 0) {
           res = res * 10 + x % 10;
        x /= 10;
    }
    return (res < -2147483648 || res > 2147483647 ) ? 0 : (int)res;//res一定要强转成int类型，不然会报错
}

```
