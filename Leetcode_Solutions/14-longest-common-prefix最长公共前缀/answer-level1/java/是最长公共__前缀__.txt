![2020020601.PNG](https://pic.leetcode-cn.com/5596d0f372a177fc36775097487129ea9ec3874672423eb26ee40500995caf96-2020020601.PNG)
### 解题思路


### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
    	String out ="";
    	boolean active = true;
    	int len = Integer.MAX_VALUE;
    	if(strs.length<1) {
    		return "";
    	}
		//先遍历一遍字符串数组，找到最短的字符串
    	for(int i=0;i<strs.length;i++) {
    		if(strs[i].length()<len) {
    			len = strs[i].length();
    		}
    	}
		//以最短字符串长度为上限,逐个比较字符串数组中不同字符串在相同索引位置的字符是否相等
    	for(int k=0;k<len;k++) {
    		for(int i=1;i<strs.length;i++) {
    			if(strs[i].charAt(k)!=strs[0].charAt(k)) {
    				active = false;
    				break;
    			}
    		}
    		if(active) {
    			if(out.length()==k) {//确保得到的公共字符是属于前缀字符
    				out += strs[0].charAt(k);
    			}
    		}
    		active = true;
    	}
        return out;
    }
}
```