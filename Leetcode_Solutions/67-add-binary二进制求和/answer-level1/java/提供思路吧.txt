### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String addBinary(String a, String b) {
          int left=a.length()-1;
	      int right=b.length()-1;
	      StringBuffer str=new StringBuffer();
	      boolean is=false;//是否进位
	      while(left>=0&&right>=0) {//不能为0
	    	  if(a.charAt(left)==b.charAt(right)) {//相同  1 1 或 0 0
	    		  str.insert(0, is?'1':'0');// 如果上一位有进位 我就是 1 	
	    		  is=a.charAt(left)=='1';//如果当前是 1 1 就进位
	    	  }else  //不相同 10 01 
	    		  str.insert(0, is?'0':"1");    	      	
	    	  left--;right--;	    	  
	      }    
			  char temp;	      
	      while(left>=0) {//左面没有找完
            temp=a.charAt(left--);           
              if(is){                  
    		  str.insert(0, temp=='1'?'0':'1');                
                      is=temp=='1';
                  
              }else
                    str.insert(0, temp);
              
	      }
	      while(right>=0) {
    		     temp=b.charAt(right--);
              if(is){
            	  str.insert(0, temp=='1'?'0':'1');                
                  is=temp=='1';
              }else
                    str.insert(0, temp);
              
	      }
            str.insert(0,is?'1': "");
		  
		  return str+"";
    }
}
```