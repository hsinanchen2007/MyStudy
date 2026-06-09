执行用时 : 5 ms , 在所有 Java 提交中击败了 83.86% 的用户，
内存消耗 : 37.6 MB , 在所有 Java 提交中击败了 72.92% 的用户
```
        char[] charArr = S.toCharArray();
		StringBuilder sb = new StringBuilder();
		int p_l = 0;
		int p_r = 0;
		for (int i = 0; i < charArr.length; i++) {
			if ('(' == charArr[i]) {
				p_l++;
			}
			if (')' == charArr[i]) {
				p_r++;
			}
			//找到原语
			if (p_l == p_r) {
				sb.append(S.substring(i - p_l * 2 + 2, i));
				p_l = 0;
				p_r = 0;
			}
		}
		return sb.toString();
```

