### 解题思路
**优化了避免字符串重复移动**

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if (s == null || s.length() == 0)
			return s;
		int replace = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s.charAt(i) == ' ')
				replace++;
		}
		char[] _s = new char[s.length() + replace * 2];
		int j = _s.length - 1;
		for (int i = s.length() - 1; i >= 0; i--) {
			if (s.charAt(i) == ' ') {
				_s[j--] = '0';
				_s[j--] = '2';
				_s[j--] = '%';
			} else {
				_s[j--] = s.charAt(i);
			}
		}
		return String.valueOf(_s);
    }
}
```