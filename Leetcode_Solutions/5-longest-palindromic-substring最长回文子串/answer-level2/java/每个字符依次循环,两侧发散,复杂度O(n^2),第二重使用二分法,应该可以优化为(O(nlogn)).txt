### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String longestPalindrome(String s) {
    	if(s == null || s.length()==0){
    		return "";
    	}
    	int re=1;
    	String ss=s.substring(0,1);
    	for(int i=0;i<s.length();i++){
    		int temp=1;
			for (int j = 1; j <= min(s.length() - i - 1, i); j++) {
    			if(s.charAt(i+j)==s.charAt(i-j)){
    				temp += 2;
    				if(temp > re){
    					re = temp;
    					ss = s.substring(i-j, i+j+1);
    				}
    			}else{
    				break;
    			}
    		}
			temp=0;
			for (int j = 1; j <= min(s.length() - i - 1, i+1); j++) {
    			if(s.charAt(i+j)==s.charAt(i-j+1)){
    				temp += 2;
    				if(temp > re){
    					re = temp;
    					ss = s.substring(i-j+1, i+j+1);
    				}
    			}else{
    				break;
    			}
    		}
    	}
    	return ss;
    }
    public int min(int i, int j){
    	return i<j?i:j;
    }
}
```