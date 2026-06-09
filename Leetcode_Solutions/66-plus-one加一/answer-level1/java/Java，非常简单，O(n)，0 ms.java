### 解题思路
数组中全部为9，则重建一个大一位的数组，第一位为1，其他位为0。
其他情况正常加1。

执行用时 :0 ms, 在所有 java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    public int[] plusOne(int[] digits) {
		for (int i = digits.length - 1; i >= 0; i--) {
			if (digits[i] != 9) {
				digits[i] = digits[i] + 1;
				return digits;
			} else {
				digits[i] = 0;
			}
		}
		int[] res = new int[digits.length + 1];
		res[0] = 1;
		return res;
    }
}
```