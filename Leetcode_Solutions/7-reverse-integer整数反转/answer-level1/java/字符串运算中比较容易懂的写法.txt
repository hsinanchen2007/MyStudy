### 解题思路

虽然执行效率不太高 不过易懂  哈哈哈哈~

### 代码

```java
class Solution {
	public int reverse(int x) {
		String s = "" + x;
		int flag = 1;
		if (x < 0) {
			flag = -1;
			s = s.substring(1);
		}
		try {
			return Integer.parseInt(new StringBuilder(s).reverse().toString())*flag;
		}catch (Exception e) {
			return 0;
		}
		
	}
}
```