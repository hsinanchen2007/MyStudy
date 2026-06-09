三种情况：
1. 如果个数相差大于1个，就不能。
2. 如果个数相同，至多允许一个字符不同，其余必须均相同，包括顺序
3. 如果个数相差1个，需要短的字符串在长的字符串中 连续 顺序 出现，且至多允许一个不连续。
```
public boolean oneEditAway(String first, String second) {
		int len1 = first.length();
		int len2 = second.length();
		if (len1 == 1 && len2 == 1) return true;
		/*接下来讨论一般情况：*/
		/*情况1:first和second长度差超过1，直接返回false*/
		if (Math.abs(len1 - len2) > 1) return false;
		/*情况2:长度相等，看看是否只有一个字母不相等，其余均相等包括顺序*/
		if (len1 == len2) return helper2(first, second);
		/*情况3，此时first和second长度相差1*/
		if (len1 > len2) return helper3(first, second);
		else if (len1 < len2) return helper3(second, first);
		return true;
	}

	/*用于处理情况2，两字符串长度相等，记录不同的位数，超过1就false*/
	private boolean helper2(String first, String second) {
		int diffCount = 0;
		for (int i = 0; i < first.length(); i++) {
			if (first.charAt(i) != second.charAt(i)) diffCount++;
			if (diffCount > 1) return false;
		}
		return true;
	}

	/*用于处理情况3，两字符串长度相差1，只有短的在长的中 连续 顺序出现，只允许至多一次不连续*/
	private boolean helper3(String first, String second) {
		int diffCount = 0;
		int i = 0, j = 0;
		while (i < first.length() && j < second.length()) {
			if (second.charAt(j) == first.charAt(i)) {
				i++;
				j++;
			} else if (second.charAt(j) != first.charAt(i)) {
				i++;
				diffCount++;
				if (diffCount > 1) return false;
			}
		}
		return true;
	}
```
