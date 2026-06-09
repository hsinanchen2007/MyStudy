利用Z形的结构来解
```
public String convertImp1(String s, int numRows) {
		// 如果是空字符则直接返回空
		if (s.length() == 0) {
			return "";
		}
		// 如果Z形的行数为1则不需要进行任何处理
		if (numRows == 1) {
			return s;
		}
		StringBuilder newS = new StringBuilder();
		// Z形变换时每个单元所含的字符个数
		int interval = numRows * 2 - 2;
		// 总共包含的单元数
		int unitNum = (s.length() / interval);
		// 按规则顺序提取字符
		// 首先把Z形的第一行全部加入
		for (int i = 0; i < s.length(); i += interval) {
			if (i < s.length()) {
				newS.append(s.charAt(i));
			}
		}
		// 把Z形的中间部分全部加入
		for (int i = 1; i < numRows - 1; i++) {
			for (int j = 0; j <= unitNum; j++) {
				if (j * interval + i < s.length()) {
					newS.append(s.charAt(j * interval + i));
				}
				if ((j + 1) * interval - i < s.length()) {
					newS.append(s.charAt((j + 1) * interval - i));
				}
			}
		}
		// 把Z形的最后一行全部加入
		for (int i = 0; i < s.length(); i += interval) {
			if (i + interval / 2 < s.length()) {
				newS.append(s.charAt(i + interval / 2));
			}
		}
		return newS.toString();
	}
```

