```java []
class Solution {
    public int firstUniqChar(String s) {
        int len = s.length();
        for(int i = 0 ; i < len; i++) {
	    if(s.lastIndexOf(s.charAt(i)) == s.indexOf(s.charAt(i))) {
	        return i;
	    }
	}
        return -1;
    }
}
```
