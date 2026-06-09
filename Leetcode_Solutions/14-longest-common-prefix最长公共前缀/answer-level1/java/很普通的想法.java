瞄题解看到很多术语和公式就不太能静下心来去读。看到题目自然会想到一个个遍历字符，我想既然所有的字符串都有公共子串，那么就可以从第一个字符串开始进行匹配。取第一个字母，与所有的字符串（除第一个）进行匹配，如果出现不等，直接返回""；然后进行下一轮循环，但是从第一个字符串取得的字母要保证其他字符串也有，防止越界。
```
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length == 0)
            return "";
        int i, j;
        for(i = 0; i < strs[0].length(); i++) {
        	for(j = 1; j < strs.length; j++) {
        		if(i < strs[j].length() && strs[0].charAt(i) != strs[j].charAt(i)) 
        		    return strs[0].substring(0, i);
        		if(i == strs[j].length())
            		    return strs[0].substring(0, i);
        	}    	
        }
        return strs[0];
    }
}
```
