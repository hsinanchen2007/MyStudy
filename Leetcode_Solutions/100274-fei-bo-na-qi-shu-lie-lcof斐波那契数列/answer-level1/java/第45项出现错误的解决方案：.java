### 解题思路
开始没有‘%1000000007’ 一直在43项还是45项报错。应该是计算溢出了吧。

所以解决方案就是计算第N个结果的时候对其取模即可。

1000000007 是最小的十位质数。模1000000007，可以保证值永远在int的范围内。
https://blog.csdn.net/yilese/article/details/76180382?depth_1-utm_source=distribute.pc_relevant.none-task&utm_source=distribute.pc_relevant.none-task
### 代码

```java
class Solution {
    public int fib(int n) {
    	if(n < 2) {
    		return n;
    	}
    	int prePreNum = 0;
    	int preNum = 1;
    	int value = 0;
    	for(int i = 2; i <= n; i++) {
    		value = (prePreNum + preNum) %1000000007;
    		prePreNum = preNum;
    		preNum = value;
    	}
    	return preNum;
    }
}
```