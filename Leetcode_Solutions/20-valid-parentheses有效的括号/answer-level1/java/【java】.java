### 解题思路
### 比较笨的方法，当在字符串s中搜索到(),{},[]子字符串时，使用空字符串替换，当完成替换后，字符串为空时，即满足条件。

### 代码

```java
class Solution {
   public boolean isValid(String s) {
    	String tempstr = s;
    	final String a = "()";
    	final String b = "[]";
    	final String c = "{}";
    	
    	int len = tempstr.length();
    	
    	while(len != 0 ) {
    		len = tempstr.length();
    		tempstr = tempstr.replace(a, "");
    		tempstr = tempstr.replace(b, "");
    		tempstr = tempstr.replace(c, "");
    		if (len != tempstr.length()) {
    			len = tempstr.length();
    		}else {
    			return false;
    		}
    	}
    	return true;
    }
}
```