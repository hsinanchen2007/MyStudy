### 解题思路
此处撰写解题思路
1、以第一个字符串为基准（初始字符串）
2、循环迭代所有字符串
3、当循环的字符串不以初始字符串开头时，从后开始截取字符串。直到找到开头为止
### 代码
```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
    	int count = strs.length;
    	if(count == 0){
    		System.out.println("字符串数组不能为空");
    		return "";
    	}
    	
    	String fixstr = strs[0];
    	for(int i=0;i<strs.length;i++){
    		while(!strs[i].startsWith(fixstr)){
    			fixstr = fixstr.substring(0, fixstr.length() - 1);
    		}
    	}
    	return fixstr;
    }
}
```