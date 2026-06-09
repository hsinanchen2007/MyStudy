```
public int compress(char[] chars) {
	int count = 0, i = 0, j = 1;
	// 保存将字符计数值转换为的字符串，方便添加到字符数组中
	String cStr = "";
	for (i = 0; i <= chars.length; i++) {
		if ((i == chars.length) || (i > 0 && chars[i] != chars[i - 1])) {
			if (count > 1) {
				cStr = Integer.toString(count);
				for (char c : cStr.toCharArray()) {
					chars[j++] = c;
				}
			}
			if (i != chars.length) {
				chars[j++] = chars[i];
			}
			count = 0;
		}
		count++;
	}
	return j;
}
```
其中i遍历原字符数组，j记录压缩后字符数组当前保存到的位置，并作为最终返回结果。