### 解题思路
一个个算，直到第n个

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if (n == 1) {
			return "1";
		}
		String pre = "1";
		while (--n > 0) {
			char[] chs = pre.toCharArray();
			int count = 1;
			char ch = chs[0];
			StringBuilder tmp = new StringBuilder();
			for (int i = 1, len = pre.length(); i < len; i++) {
				if (ch == pre.charAt(i)) {
					count++;
				} else {
					tmp.append(count);
					tmp.append(ch);
					count = 1;
					ch = pre.charAt(i);
				}
			}

			tmp.append(count);
			tmp.append(ch);

			pre = tmp.toString();
		}

		return pre;
    }
}
```