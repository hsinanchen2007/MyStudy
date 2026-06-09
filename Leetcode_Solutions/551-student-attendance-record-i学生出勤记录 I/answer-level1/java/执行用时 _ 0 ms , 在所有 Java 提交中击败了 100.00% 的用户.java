### 解题思路
判断A出现次数
若满足再判断字符串S中是否有"LLL"
若有则不成立

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        int count =0;//记录A出现的次数
		for(int i=0;i<s.length();i++) {
			count+=s.charAt(i)=='A'?1:0;
			if(count==2) {
				return false;
			}
		}
		if(s.indexOf("LLL")==-1) {
			return true;
		}
		return false;
    }
}
```