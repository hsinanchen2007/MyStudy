### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
   public static String compressString(String S) {
		
		 char[] ca=S.toCharArray();
		 if(ca.length==0)return "";
	     StringBuilder res=new StringBuilder();
	     res.append(ca[0]);
	     int sum=1;
	     char s=ca[0];
	     for(int i=1;i<=ca.length;i++){
	    	 
	    	 if(i==ca.length){
	    		 res.append(sum);
	    	 }
	    	 else if(ca[i]==s) {
	    		 sum++;
	    	 }else  {
	    		 s=ca[i];
	    		 res.append(sum);
	    		 res.append(s);
	    		 sum=1;
	    	 }
	     }
	     
	     
	     if(res.length()<ca.length) {
	    	 return res.toString();
	     }else {
	    	 return S;
	     }
    }
}
```