不借助库方法。
Java库方法有Integer.bitCount(n)，后附源码，可参考。
```java
public class Solution {
    public int hammingWeight(int n) {
		int count = 0;
		while (n != 0) {
			//如果二进制最后一位是1的话count+1，否则是0则+0(相当于不加)
			count += (n & 1);
			n = n >>> 1;
		}
		return count;
    }
}
```

Java库方法
```java
public static int bitCount(int i) {
    // HD, Figure 5-2
    i = i - ((i >>> 1) & 0x55555555);
    i = (i & 0x33333333) + ((i >>> 2) & 0x33333333);
    i = (i + (i >>> 4)) & 0x0f0f0f0f;
    i = i + (i >>> 8);
    i = i + (i >>> 16);
    return i & 0x3f;
}
```
