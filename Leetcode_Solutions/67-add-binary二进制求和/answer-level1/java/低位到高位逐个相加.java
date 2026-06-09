### 解题思路
此处撰写解题思路
思路：从低位（却是字符串的高位）到高位逐个相加，并用flag标记是否有进位，循环len次，等到结果。
1. 循环次数是长度较大的那个，取max即可
2. 若两个字符串长度不一样，可能会出现越界的情况，需要判断索引是否越界
3. 取出的字符转为Int型是其ASCII码，需要减去48，因为0的码是48，越界直接取0即可
4. 最后别忘了判断是否还有一个进位，若有，在字符串最前面加+1即可
### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
		int len1 = a.length();
		int len2 = b.length();
		int len = Math.max(a.length(), b.length());
		String ans = "";
		int flag = 0;
		for (int i=0; i<len; i++) {
			int cur1 = i<len1 ? a.charAt(len1-1-i)-48 : 0;
			int cur2 = i<len2 ? b.charAt(len2-1-i)-48 : 0;
			int cur = cur1 + cur2 + flag;
			flag = cur / 2;
			ans = cur%2 + ans;
		}
		if (flag==1) ans = 1+ans;
		return ans;

    }
}
```