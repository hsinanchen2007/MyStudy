## 执行
```
执行用时 : 3 ms, 在Add Binary的Java提交中击败了97.73% 的用户
内存消耗 : 34.5 MB, 在Add Binary的Java提交中击败了90.75% 的用户
```
## 思路
不考虑二进制转十进制进行加法再转换回二进制的方法，这种方法有可能会出现溢出。

1. 先找出最长字符串，指定长的为 a，短的为 b。
2. 将 a 转为字符数组，并以此进行加法，用 carry 记录进位。
3. 遍历字符数组，进行加法运算。
4. 注意 1：b 比 a 短，所以会先到达 0 坐标点，此时 b 跟 a 加的字符应当为 '0'
5. 注意 2：如果 a 到达0坐标仍有进位，此时要把1加到第一位。

## 实现
```
class Solution {
	public String addBinary(String a, String b) {
		if (a.length() < b.length()) {
			String tmp = a;
			a = b;
			b = tmp;
		}
		char[] charsA = a.toCharArray();
		int aLength = charsA.length - 1;
		int bLength = b.length() - 1;
		char carry = '0';
		while (aLength >= 0) {
			char charsB = '0';
			if (bLength >= 0) {
				charsB = b.charAt(bLength);
			}
			if (charsA[aLength] == charsB) {
				charsA[aLength] = carry;
				if (charsB != '0') {
					carry = '1';
				}else {
					carry = '0';
				}
			}else {
				if (carry == '0') {
					charsA[aLength] = '1';
				}else {
					charsA[aLength] = '0';
					carry = '1';
				}
			}
			bLength --;
			aLength --;
		}
		return carry == '0'? String.valueOf(charsA):"1"+ String.valueOf(charsA);
	}
}
```