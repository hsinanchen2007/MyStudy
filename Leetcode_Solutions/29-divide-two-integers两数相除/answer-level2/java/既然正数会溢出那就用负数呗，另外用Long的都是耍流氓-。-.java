
![image.png](https://pic.leetcode-cn.com/9f0dae1d907ed685476ed9ed7acb02ee723cbb00a1f083a4f9b1e1cd7ce09bcc-image.png)

# 逆向思维反向操作很重要
既然正数存在溢出那就用负数来进行计算，最后再处理符号问题即可；
# 位运算也要循环不断提速
位运算也是需要循环减小除数值的，我第一次只用了一次位运算，500ms+，很是纳闷...
因为被除数可能会被左移的太多了，所以可以用除数减去已经获得的最大位移后的被除数，然后复位除数，循环进行位操作即可；
#特殊情况尽量单独处理
对于0，1，-1，相等，都转负数后被除数小于除数，最大值、最小值的边界问题拎出来单独处理也很重要；
# 用Long就是耍流氓
题干的**说明**部分第3点已经明确了只能存储 32 位有符号整数，所以这道题还是必须在[Integer.MIN_VALUE,Integer.MAX_VALUE]内解决的，不能使用Long扩大范围；


```
	public int divide(int dividend, int divisor) {
		// 被除数为0时快速返回
		if (divisor == 0) {
			return 0;
		}
		// 相等时快速返回
		if (dividend == divisor) {
			return 1;
		}
		// 唯一的商会溢出的情况，单独处理
		if (dividend == 只能存储 32 位有符号整数 && divisor == -1) {
			return Integer.MAX_VALUE;
		}
		// 为1时快速返回
		if (divisor == 1 || divisor == -1) {
			return divisor == 1 ? dividend : -dividend;
		}
		// 使用异或位运算记录商的符号
		boolean flag = (dividend ^ divisor) > 0 ? false : true;
		int d1 = dividend;
		int d2 = divisor;
		// 都转为负数
		d1 = d1 > 0 ? -d1 : d1;
		d2 = d2 > 0 ? -d2 : d2;
		// 被除数小于除数时快速返回
		if (d1 > d2) {
			return 0;
		}
		int d3 = d2;
		int quotient = 0;
		// 位运算的中间值
		int multiple = 1;
		while (d1 <= d3) {
			// 2倍循环扩大被除数值，满足条件时获得相应的局部商值multiple
			while ((d2 << 1) < 0 && d1 <= (d2 << 1)) {
				multiple <<= 1;
				d2 <<= 1;
			}
			// 记录局部商值
			quotient += multiple;
			// 各种值复位，以及获得减去d2位移后剩余的新被除数，并复位d2为初始被除数后再进行位移操作
			// 这里是关键，因为第一次可能d2位移的过于大，所以d1减去已获得的最大d2并将d2复位后继续进行位移操作
			d1 -= d2;
			d2 = d3;
			multiple = 1;
		}
		return flag ? -quotient : quotient;
	}
```
