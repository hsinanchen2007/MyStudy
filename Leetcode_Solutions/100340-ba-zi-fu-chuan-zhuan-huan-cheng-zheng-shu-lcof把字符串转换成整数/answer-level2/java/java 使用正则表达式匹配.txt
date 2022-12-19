### 解题思路
使用正则表达式
捕获组 "^(\\s*)([-|+]?)(\\d+)"
^表示从字符串开始的位置开始匹配，排除字符串首字符为字母，数字出现在后面的情况
(\\s*)第一个捕获组用来匹配空格 group(1)
([-|+]?) ？表示-或者+出现0次或者1次 group(2)
(\\d+) 表示匹配数字，+表示出现1次或多次 group(3)
catch(NumberFormatException e)用来捕获超-2^31~2^31-1区间的异常
### 代码

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Solution {
	    public int strToInt(String str) {
	    	String regex ="^(\\s*)([-|+]?)(\\d+)";
	    	Pattern r= Pattern.compile(regex);
	    	Matcher matcher =r.matcher(str);
	    	if(matcher.find()){
	    		try{	    			
	    			if(matcher.group(2).equals("-")){	    				
	    				return -Integer.valueOf(matcher.group(3));
	    			}else{
	    				return Integer.valueOf(matcher.group(3));
	    			}		    		
		    	}catch(NumberFormatException e){
		    		if(matcher.group(2).equals("-")){
		    			return Integer.MIN_VALUE;
		    		}else{
		    			return Integer.MAX_VALUE;
		    		}
		    		
		    	}
	    	}
	    	
	    	return 0;
	    }
}
```