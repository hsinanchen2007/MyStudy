### 解题思路
算是开拓思路吧,效率不佳的方法

### 代码

```java
class Solution {
    public boolean backspaceCompare(String S, String T) {
    	S=S.replaceAll("\\w#", "");
    	T=T.replaceAll("\\w#", "");
    	while(S.contains("#")) {
    		if(S.charAt(0)=='#')S = S.substring(1);
    		else S=S.replaceAll("\\w#", "");
    	}
    	while(T.contains("#")) {
    		if(T.charAt(0)=='#')T = T.substring(1);
    		else T=T.replaceAll("\\w#", "");
    	}
    	return S.equals(T);
    }
}
```