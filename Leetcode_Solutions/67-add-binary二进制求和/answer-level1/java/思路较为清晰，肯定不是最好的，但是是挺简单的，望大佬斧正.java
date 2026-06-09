### 解题思路
此处撰写解题思路
第一步，先把length 用0补成一样，比如 11 和 1111 补后 0011 1111，不影响值
然后定义ca carry 也就是进位，初始为0，
之后就是加法的核心了，单一位的二进制加法无外乎 0 ， 1 ，2 ，3 三种情况，结果为0和1 直接算 ca =0
结果为2，写0，下一轮ca = 1, 3 就是上一轮ca为1，1+1+1，写1 ca 进1
之后重点，如果最后一步ca还是1，说明是类似 10+10，就是需要多一位的运算，所以在返回前，判断此时的ca是不是0，
不是的话，直接在首位增1。

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
		StringBuilder str = new StringBuilder();
		// find the long length
		// int lowLen = a.length() <= b.length() ? a.length() : b.length();
		while(a.length() != b.length()) {
			if (a.length() > b.length()) {
				b = "0"+b;
			} else if (a.length() < b.length()) {
				a = "0"+a;
			}
		}
		// 定义进位carry

		int ca = 0;
		for (int i = a.length()-1; i >= 0; i--) {
			switch (Character.getNumericValue(a.charAt(i)) + Character.getNumericValue(b.charAt(i)) + ca) {
			case 0:
				str.append("0");
				ca = 0;
				break;
			// 1 + 0 + 0 or 0 + 1 + 0 or 0+0+ca(1); ca = 0
			case 1:
				str.append("1");
				ca = 0;
				break;
			// 1+1 >> 0 ; ca >> 1
			case 2:
				str.append("0");
				ca = 1;
				break;
			// 1+1+ca(1) >> 1 ; ca > 1
			case 3:
				str.append("1");
				ca = 1;
				break;
			default:
				break;
			}
		}
		if (ca == 1)
			str.append("1");
		return str.reverse().toString();
    }
}
```