### 解题思路
此处撰写解题思路
思想：将待用字符压入栈中，逐个将字符出栈，并寻求匹配。若栈空字符串仍有未匹配者，说明该字符串无法拼写。
1. 将待用字符全部入栈
2. 外层循环，是单词的个数
3. 内层循环，出栈的次数，也即待用字符的个数
4. 若匹配，则从字符串中清除这个字符，若不匹配，continue
5. 全部字符出栈后，结束循环，若此时字符串中仍有元素，则不能拼写该单词，计数也当清0
### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
		int len = words.length;
		if (len==0) return 0;
		int res = 0;
		int num = chars.length();
		for (int i=0; i<len; ++i) {
			Stack<Character> s = new Stack<>();
			for (int j=0; j<num; ++j) s.push(chars.charAt(j));//将所有字母都压入栈中
			String cur = words[i];
			int count= 0;
			for (int k=0; k<num; ++k) {				
				String tem = s.pop()+"";
				if (cur.contains(tem)) {
					cur = cur.replaceFirst(tem, "");
					count++;
					
				}
				if (s.isEmpty() && !cur.isEmpty()) {
					count = 0;
					break;
				}
			}
			res += count;
		}
		return res;
    }
}
```