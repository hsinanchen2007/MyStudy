### 解题思路

遍历，
先清理开头的空白符；
再清理正负号，并记录；
然后，遇到非数字，直接截断返回；

重点处理数字。
关键点在于，处理数字时的边界值处理。


### 代码

```java
class Solution {
    public int myAtoi(String str) {
        int ans = 0, index = 0;

    	// 空白符
		while(index < str.length() && str.charAt(index)==' ') {
			index++;
		}
		if(index == str.length()) return 0;// 全空白符，或空字符串
		
		//正负号
		boolean positive = true; 
		if(str.charAt(index)=='+') index++; 
		else if(str.charAt(index)=='-') {
			index++;
			positive = false;
		}
		
		// 边界值
		int limit = positive?-Integer.MAX_VALUE:Integer.MIN_VALUE;
		
		//逐个读取数字
		while(index<str.length() && 
				str.charAt(index)<='9' && str.charAt(index)>='0') { // 非数字时截断
			int digit = (str.charAt(index++)-'0');
			
			// 边界值处理
			if(ans<(limit+digit)/10){
                return positive?Integer.MAX_VALUE:Integer.MIN_VALUE;
            }
			
			ans=ans*10-digit; //用减法
		}
    	
		return positive?-ans:ans;
    }
}
```