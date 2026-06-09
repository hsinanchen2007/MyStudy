

抖机灵想出来的，为了防止数组越界，我直接while（1），让他必定越界，这时就说明已经比较完了（或者说最短的那个string已经被榨干了。。。），此时只要来一个异常处理就可以了，直接返回之前保存的那个字符串。为了防止开局给空数组，所以try要在compare=strs[0].charAt(0);之前。剩下的就很容易看懂了，欢迎大佬批评指点！

```java
class Solution {
 public String longestCommonPrefix(String[] strs) {
     String save="";
     try {
         
		 char compare=strs[0].charAt(0);//用于比较prefix
		 int index=0;
		
	    
	 
		 while(true){
	    	for(String i:strs){
	    		if(compare!=i.charAt(index))
	    			return save;
	    		
	    			
	    	}
	    	save+=compare;
	    	index++;
	    	compare=strs[0].charAt(index);
	    }
		}catch(IndexOutOfBoundsException e){//数组越界说明已经比较完毕，返回结果就可以
			return save;
	 	}
 }
}
```