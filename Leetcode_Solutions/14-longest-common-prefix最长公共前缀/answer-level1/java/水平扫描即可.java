### 解题思路
此处撰写解题思路
通过idx位来获取每个字符串的第idx位，相同则ok，不通则return
### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length <1){
			return "";
		}
		String first = strs[0];
		int idx = 0;
		while (true){
			char tmp = '*';
			for (String str : strs) {
				if(idx == str.length()){
					return str;
				}
				if(tmp == '*'){
					tmp = str.charAt(idx);
					continue;
				}
				if(tmp != str.charAt(idx)){
					return first.substring(0,idx);
				}

			}
			idx++;
		}
	}
}
```