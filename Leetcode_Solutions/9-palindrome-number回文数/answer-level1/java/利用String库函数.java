### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
 	String str= new String();
    	String str2=new String();
    	str=String.valueOf(x);
    	StringBuffer s = new StringBuffer(str);
    	str2=s.reverse().toString();
    	if(str2.equals(str))
    		return true;
    	else
    		return false;
    }
}
```