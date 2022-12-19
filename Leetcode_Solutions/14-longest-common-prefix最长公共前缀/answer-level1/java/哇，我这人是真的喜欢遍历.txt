```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        StringBuilder commonPrefix = new StringBuilder("");
        
		// 若只有一个字符串则返回第一个字符串
		if(strs.length == 1)
			return strs[0];
		// 若为空集则返回空字符串
		else if (strs.length == 0)
			return "";
        
		// 获取最短字符串，以其长度参考
		int length = strs[0].length();
		for(int i = 0; i < strs.length; i ++) {
			if(strs[i].length() < length)
				length = strs[i].length();
		}
		
		// 检索字符串的字母，并逐次比较
		for(int j = 0; j < length; j++) {
			for(int k = 0; k < strs.length - 1; k++) {
				if(strs[k].charAt(j) != strs[k + 1].charAt(j))
					return commonPrefix.toString();
				}
			commonPrefix.append(strs[0].charAt(j));
		}
		return commonPrefix.toString();
	}
}
```