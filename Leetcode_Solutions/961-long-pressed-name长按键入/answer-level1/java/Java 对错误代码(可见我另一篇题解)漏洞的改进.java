### 解题思路

在这里对 typed 后面的字符也进行了判断

### 代码

```java
class Solution {
    public boolean isLongPressedName(String name, String typed) {
	    int i=0;
    	int j=0;
	    for(;i<typed.length();i++){
	        if(name.charAt(j)==typed.charAt(i)){
	            j++;
	        }
	        if(j==name.length())
	            break;
	        
	    }
	    boolean isRight = true;
	    for(;i<typed.length();i++) {
	    	if(typed.charAt(i)!= name.charAt(name.length()-1))
	    		isRight = false;
	    }
	    return j==name.length() && isRight;   
    } 
}
```