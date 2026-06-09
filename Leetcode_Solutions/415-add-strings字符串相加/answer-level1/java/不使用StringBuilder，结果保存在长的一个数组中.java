### 解题思路
![image.png](https://pic.leetcode-cn.com/c15d7c4dad06e594b0102d1ef6333f26390db1e281593c2ce598be64cbebb405-image.png)
计算的模式没变，但是优化后不使用StringBuilder，考虑转char数组然后用其中长的一个保存求和结果，只在最后返回的时候new出最终的串；


### 代码

```java
class Solution {
    public String addStrings(String num1, String num2) {
		num1 = num1 == null ? "0" : num1;
		num2 = num2 == null ? "0" : num2;
		int len1 = num1.length();
		int len2 = num2.length();
		if (len1 > len2) {
			String s = num1;
			num1 = num2;
			num2 = s;
			int t = len1;
			len1 = len2;
			len2 = t;
		}
		char[] cs1 = num1.toCharArray();
		char[] cs2 = num2.toCharArray();
		char c;
		int p = len2 - len1;
		boolean carry = false;
		for (int i = len1 - 1; i >= 0; i--) {
			c = (char) (cs1[i] + cs2[p + i] - '0');
			if (carry) {
				c++;
			}
			if (c > '9') {
				c -= 10;
				carry = true;
			} else {
				carry = false;
			}
			cs2[p + i] = c;
		}
		if (len2 > len1) {
			for (int i = p - 1; i >= 0; i--) {
				if (!carry) {
					break;
				}
				c = cs2[i];
				c++;
				if (c > '9') {
					c -= 10;
					carry = true;
				} else {
					carry = false;
				}
				cs2[i] = c;
			}
		}
		return carry ? "1" + new String(cs2) : new String(cs2); 
    }
}
```