将末尾的空格略去，从倒数第一个非空格的字符开始统计，直到遇到空格为止。

```
	public int lengthOfLastWord(String s) {
		int num = 0, len = s.length();
		while (len > 1 && s.charAt(len - 1) == ' ')
			len--;
		for (int i = len - 1; i >= 0; i--) {
			if (s.charAt(i) == ' ')
				return num;
			else
				num++;
		}
		return num;
	}
```
