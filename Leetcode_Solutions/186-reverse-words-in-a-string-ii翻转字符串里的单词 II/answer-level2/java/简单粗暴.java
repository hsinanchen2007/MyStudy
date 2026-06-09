### 解题思路
此处撰写解题思路
1.先reverse单个单词的顺序
2.在整体数组reverse

### 代码

```java
class Solution {
   public void reverseWords(char[] s) {
		if (s == null || s.length < 2)
			return;
		int index = 0;
		for (int i = 0; i < s.length; i++) {
			if (s[i] == ' ') {
				reverseWords(s, index, i - 1);
				index = i + 1;
			}
			if (i == s.length - 1) {
				reverseWords(s, index, i);
			}
		}
		reverseWords(s, 0, s.length - 1);
	}

	public void reverseWords(char[] s, int startIndex, int endIndex) {
		int mid = (startIndex + endIndex) >>> 1;
		for (int i = startIndex; i <= mid; i++) {
			char swap = s[i];
			s[i] = s[endIndex];
			s[endIndex] = swap;
			endIndex--;
		}
	}
}
```