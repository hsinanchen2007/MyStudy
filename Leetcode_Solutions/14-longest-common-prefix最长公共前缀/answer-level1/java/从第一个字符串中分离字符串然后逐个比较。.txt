### 解题思路
    一开始从一个字符串中提取出一个字符，并将这个字符与后面的字符串进行比较，若是相同，则继续比较，并继续从第一个字符串中提取字符，直到比较到不同之处，此时返回相同的字符串即可。

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        int len_1=strs.length;
        if(len_1==0){return "";}
	     int len_2=strs[0].length();
	     //选取比较的最终长度
	     for (int i=1;i<len_1;i++)
	     {
	    	 if(strs[i].length()<len_2)
	    	 {
	    		 len_2=strs[i].length();
	    	 }
	     }
	     int len_same=0;
	     int len_comp=1;
	     int flag=1;
	     while(len_comp<=len_2)
	     {
	    	 
	    	 //每次比较的字符串
	    	 char str_cmp[]=new char[len_comp];
	    	 for(int i=0;i<len_comp;i++)
	    	 {
	    		 str_cmp[i]=strs[0].charAt(i);
	    	 }
	    	 String s_comp=new String(str_cmp); 
	    	 for(int i=1;i<len_1;i++)
	    	 {
	    		 if(!strs[i].startsWith(s_comp))
	    		 {
	    			flag=0;	    		
	    		 }
	    	 } 
	    	 if(flag==0)
	    		 break;
	    	 len_same++;
	    	 len_comp++;
	     }
	    
	     //确定返回值
	     if(len_same==0)
	     {
	    	 return "";
	     }
	     else 
	     {
	    	 
	         char[] ans=new char[len_same];
	         for(int i=0;i<len_same;i++)
	         {
	        	 ans[i]=strs[0].charAt(i);
	         }
	         String str_ans=new String(ans);
	         return str_ans;
	     }
    }
}
```