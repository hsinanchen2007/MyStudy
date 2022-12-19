### 解题思路
1.用递归时间就超了
2.最后才处理结果会导致数字溢出（long也不行）
3.提前处理答案

### 代码

```java
class Solution {
    public int fib(int n) {
    	if (n < 2) {
			return n;
		}
    	int a = 0;
    	int b = 1;
    	int c = 1;
    	for (int i = 2; i <= n; i++) {
			c = a + b;
			c %= 1000000007;
			a = b;
			b = c;
		}
    	return c;
    }
}
```