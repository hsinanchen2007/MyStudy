执行用时 : 88 ms, 在Longest Palindromic Substring的Java提交中击败了45.87% 的用户
内存消耗 : 35.2 MB, 在Longest Palindromic Substring的Java提交中击败了93.71% 的用户

这是耗时最短的一次，提交多几次都是在110ms左右

遍历每个字符，从后往前查相同字符，并从两个字符往里查找。
这优化的暴力法可太耗时了只能好好看看领悟下官方题解，学习学习

```
class Solution {
	public String longestPalindrome(String s) {
        if(s == null || s.length() == 0){
            return "";
        }
		char[] chars = s.toCharArray();
		int num = chars.length - 1;
		int maxLength = 0;
		int left = 0;
		int right = 0;
		for (int i = 0; i < chars.length - maxLength; ) {
			char ch = chars[i];
			int pos = s.lastIndexOf(ch, num); //定位相同字符
			if (i == pos || pos - i < maxLength) {
				i++;
				num = chars.length - 1;
				continue;
			}
			int posRec = pos;
			pos--;
			boolean success = true;
			for (int j = i + 1; j < pos; j++, pos--) { //判断是否回文字符串
				if (chars[j] != chars[pos]) {
					success = false;
					break;
				}
			}
			if (success) {  //记录位置
				maxLength = posRec - i;
				left = i;
				right = posRec;
			}
			num = posRec - 1;
		}
		return s.substring(left, right + 1);
	}
}
```