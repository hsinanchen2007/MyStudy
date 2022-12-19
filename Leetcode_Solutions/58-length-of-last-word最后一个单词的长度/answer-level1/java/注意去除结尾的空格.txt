### 解题思路
1.判断空字符串的情况
2.trim()去除结尾的空格
3.用字符串的总长度减去第一次出现空格的位置再减1，就是最后一个单词的长度
### 代码

```java
class Solution {
    public int lengthOfLastWord(String s) {
    	if (s.equals("")) {
			return 0;
		}
    	return s.trim().length() - s.trim().lastIndexOf(" ") - 1;
    }
}
```