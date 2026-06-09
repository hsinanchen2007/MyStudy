### 解题思路
从最后一位开始往前迭代

如果之前的迭代返回结果改变了，说明有过反转，那么不做反转

否则本次反转

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        if (num == 0) {
			return num;
		}

		int n = num % 10;
		int n1 = num / 10;
		int n2 = maximum69Number(n1);
		if (n2 > n1) {
			// 反转过了
			return n2*10+n;
		} else {
			if (n == 6) {
				// 反转一次
				return num + 3;
			}else {
				return num;
			}
		}
    }
}
```