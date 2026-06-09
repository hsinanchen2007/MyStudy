### 解题思路
先找出长度最短的字符串，然后遍历所有字符串，看每个字符串是否以这个字符串开头。如果不是，就去掉这个最短的字符串的最后一个字符，并重新开始遍历字符串数组。

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int size = strs.length;
		if (size == 0) {
			return "";
		}
        String shortest = strs[0];
		for (int i = 1; i < size; i++) {
			if (strs[i].length() < shortest.length()) {
				shortest = strs[i];
			}
		}
		int i = 0 ;
		while (i < size && shortest.length() > 0) {
			if (strs[i].startsWith(shortest)) {
				i++;
			} else {
				shortest = shortest.substring(0, shortest.length()-1);
				i = 0;
			}
		}
		return shortest;
    }
}
```