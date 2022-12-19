### 解题思路
例如如果想要反转，有如下思路：
对于两位数的48，即40 + 8,然后想办法从右面开始把个位数8取出来，然后剩了40，在除10，可以获得4，反转后的算法为：4*10 + 8
对于三位数的123,即100 + 20 + 3,依次取出个位3，除10去2，除100取1，反转后为3*100 + 2*10 + 1，即每次加1位就要乘以10
依次类推：。。。。
最后大概会有如下代码：


### 代码

```java
public static void main(String[] args) {
		System.out.println(reverse(48));
	}
	
	public static int reverse(int x) {
		long r = 0;
		while (x != 0) {
			r = r * 10 + x % 10;
			x = x / 10;
		}
		if (r > Integer.MAX_VALUE || r < Integer.MIN_VALUE) {
			return 0;
		}
		return (int) r;  
	 }
```