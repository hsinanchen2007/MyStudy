### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        int length = str1.length();
        int length2 = str2.length();
		for(int i=length-1;i>=0;i--) {
        	String s = "";
			String str = str1.substring(0, i+1);
			for(int j=1;j<=length/(i+1);j++) {
				s+=str;
			}
			if(s.length()!=length) {
				continue;
			}
			String s2 = "";
			for(int j=1;j<=length2/str.length();j++) {
				s2+=str;
			}
			if(s2.length()!=length2) {
				continue;
			}
			if(s.equals(str1)&&s2.equals(str2)) {
				return str;
			}
        }
		return "";
    }
}
```