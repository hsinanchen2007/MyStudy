### 解题思路

这一题和后面有一道题很像，后面有一道题是十进制数的加法，做的时候因为要考虑整数溢出，所以采用的是和这道题一样的算法。

- 从后向前遍历，每次只关注三个变量，字符串a和b的这一位字符的数值，carry进位；

  append 余数；carry 是商；完成后反转 string 或者 stringBuilder

- 值得说的一点是：根据 ` a.charAt(i)-'0' ` 求十以内的值比较好用，这在后面很多题中也有用到

- 后面还会有 ` a.charAt(i)-'a' ` 可以求出来某个小写字母相对于 a 的位置，多和数组结合使用

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
        int carry=0;
		int i = a.length()-1;
		int j = b.length()-1;
		StringBuilder sBuilder = new StringBuilder();
		while(i>=0 || j>=0) {
			int sum = carry;
			sum += i>=0 ? a.charAt(i)-'0' : 0;
			sum += j>=0 ? b.charAt(j)-'0' : 0;
			sBuilder.append(sum%2);
			carry = sum/2;
            i--;
            j--;
		}
		if(carry!=0) {
			sBuilder.append(carry);
		}
		return sBuilder.reverse().toString();
    }
}
```