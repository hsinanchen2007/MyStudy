### 解题思路
此处撰写解题思路

### 代码

```java
/*
 * @time 上午11:49:01
*/
class Solution {
	public boolean isMatch(String text, String pattern) {

		/**
		 if (pattern.isEmpty()) {
			return text.isEmpty();
		}
		boolean first = (!text.isEmpty()) && (text.charAt(0) == pattern.charAt(0) || pattern.charAt(0) == '.');
		return first && (isMatch(text.substring(1), pattern.substring(1)));
		 */

		/*
		 * 那么如果考虑‘*’呢，首先我们需要考虑‘*’的意义， text和pattern,只有当pattern可以完全变为等价于text的形式才会返回true;
		 * 对于‘*’，表示含义： “ab*”表示 a+(0或任意正整数个b),因此它可以匹配“a”’,也可以匹配"abbbb.....";
		 */
		/*
		 * 首先可以肯定第一个字符不可能为‘*’，这里我们假设输入的正则表达式都是有意义的； 如果第i个字符后面的字符为‘*’,那么第i个字符可以以任意个出现；
		 * 我们可以继续比较text的下一个字符(i+1)，而pattern不作移动；
		 * 或者可以继续比较pattern的‘*’之后的字符串，说明为了满足text，pattern已经不需要第i个字符的出现；
		 * 只要这两种方法有一种可以，则匹配成功；NFC;
		 */
		if (pattern.isEmpty())
			return text.isEmpty();
		boolean first = (!text.isEmpty()) && (text.charAt(0) == pattern.charAt(0) || pattern.charAt(0) == '.');
		if (pattern.length() >= 2 && (pattern.charAt(1) == '*')) {
			return (isMatch(text, pattern.substring(2)) || (first && isMatch(text.substring(1), pattern)));
		} else {
			return first && isMatch(text.substring(1), pattern.substring(1));
		}
	}

}

```