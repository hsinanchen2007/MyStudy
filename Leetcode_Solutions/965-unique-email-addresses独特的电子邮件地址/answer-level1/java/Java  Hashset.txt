### 解题思路
利用Hashset记录地址，代码清晰易懂

### 代码

```java
class Solution {
    public int numUniqueEmails(String[] emails) {
    	HashSet h =new HashSet<>();
    	for (String s:emails) {
        	StringBuffer sb =new StringBuffer();	
    		char[] c=s.toCharArray();
    		int i=0;
			while (c[i]!='@') {
				  if(c[i]=='.')
					i++;
				  else if (c[i]=='+') {
					 while (c[i]!='@') 
						i++;
				  }
				  else {
					 sb.append(c[i]);
					 i++;
				  }
			    }
			while (i<c.length) {
				    sb.append(c[i]);
				    i++;
			}
    	h.add(sb.toString());	
		}
    	return h.size();
    }
}
```