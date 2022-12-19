### 解题思路
    进行遍历即可，遍历的过程中，碰到大写的转化为小写即可。

### 代码

```java
class Solution {
    public String toLowerCase(String str) {
         char[] ans=str.toCharArray();
		  for(int i=0;i<str.length();i++)
	     {
	         if(ans[i]>=65&&ans[i]<=90)
	        	 ans[i]=(char)(ans[i]+32);
	        	 
	     }
		  return new String(ans,0,ans.length);
    }
}
```