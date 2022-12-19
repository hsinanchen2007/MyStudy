### 解题思路
用count记录匹配的个数，若值为s.length()则匹配成功

### 代码

```java


class Solution {
    public boolean isSubsequence(String s, String t) {
       	    int j=0;
	        int count=0;
	        for(int i=0;i<s.length();i++){
	            for(;j<t.length();){	            
	                if(s.charAt(i)==t.charAt(j)){
	                    count++;
	                    j++;
	                    break;
	                }else {
	                	j++;//防止break后j的值没有+1
					}
	                
	            }
	        }
	        
	        if(count==s.length()){
	            return true;
	        }else{
	            return false;
	        }
    }
}
```