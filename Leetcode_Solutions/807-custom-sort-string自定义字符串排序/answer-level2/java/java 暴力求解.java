### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String customSortString(String S, String T) {
    	StringBuffer res=new StringBuffer();
    	int[] help=new int[T.length()];
        for (int i = 0; i < S.length(); i++) {
        	for (int j = 0; j < T.length(); j++) {
				if(S.charAt(i)==T.charAt(j)){
					help[j]=1;
					res.append(T.charAt(j));
				}
			}	
		}
    	for (int j = 0; j < T.length(); j++) {
			if(help[j]!=1)
				res.append(T.charAt(j));	
		}
        return res.toString();
    }
}
```