### 解题思路

遍历查看needle这个字符串是否在haystack这个字符串中，但是现在肯定是优化的空间的。

![image.png](https://pic.leetcode-cn.com/6bd6fa17c95d9f02c822a7b3c6368e97ee08d0475ef8be5f56f1106557b0a144-image.png)


### 代码

```java
class Solution {
    public int strStr(String haystack, String needle) { 
		for (int i = 0; i <= haystack.length(); i++) {			 
			if (i + needle.length() > haystack.length()) {
				return -1;
			} 	 
			if (haystack.substring(i,i+needle.length()).equals(needle)) {
				return i;
			}  
		}  
		return -1;
    }
}
```