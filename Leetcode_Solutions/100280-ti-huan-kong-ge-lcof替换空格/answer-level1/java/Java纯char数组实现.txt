就不抖正则了，也没用到StringBuilder，遍历实现，思路在注释详细说明。
```java
class Solution {
	public static String replaceSpace(String s) {
		//如果s全是空格的话所需的数组大小会是s的3倍，这是极端情况
		char[] reChar = new char[s.length() * 3];
		int size = 0;
		for (char c : s.toCharArray()) {
			if (c == ' ') {
				reChar[size++] = '%';
				reChar[size++] = '2';
				reChar[size++] = '0';
			} else {
				reChar[size++] = c;
			}
		}
		//可能数组空间申请过大，裁剪所需的长度转为字符串后再返回
		return new String(reChar, 0, size);
	}
}
```