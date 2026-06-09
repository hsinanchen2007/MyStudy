### 解题思路

嵌套for循环

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
    	if (strs.length == 0) // 判断传入数组长度
    		return "";

    	String commonString = ""; // 设置初始字符串

    	for (int i = 0; i < strs[0].length(); i++) { // 取数组第一个元素的长度, 作为外循环的次数
    		char currentChar = strs[0].charAt(i); // 取到当前字符索引

    		for (String str : strs) {
    			if (str.length() <= i || str.charAt(i) != currentChar) {
    				return commonString;
    			}
    		}
    		commonString = strs[0].substring(0, i+1);
    	}

    	return commonString;
    }
}
```