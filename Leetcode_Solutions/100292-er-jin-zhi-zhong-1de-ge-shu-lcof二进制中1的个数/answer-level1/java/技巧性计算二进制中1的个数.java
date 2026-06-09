### 解题思路
不断计算n=n&(n-1)，当n=0是退出循环，每次循环计数加1。eg.1001。第一次计算n！=0，所以count++，1001&1000=1000。第二次计算1000！=0，所以count++，1000&0111=0。第三次就跳出循环，得count=2。

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        if(n==0)
			return 0;
		int c = 0;
		while(n!=0) {
			c++;
			n = n & (n-1);
		}
		
		return c;
    }
}
```