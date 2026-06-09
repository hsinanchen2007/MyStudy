### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
  	  public List<String> restoreIpAddresses(String s) {
		  
           LinkedList<String> re=new LinkedList();
           if(s.length()<4)
        	   return re;
           else if(s.length()==4){
        	   String s2="";
        	   for(int i=0;i<3;i++){
        		   char ch=s.charAt(i);
        		   s2=s2+ch+".";
        	   }
        	   s2+=s.charAt(3);
        	   re.add(s2);
        	   return re;
        	   
           }
           backtrace(s,0,re,"");
           return re;
	    }
	  private void backtrace(String s, int start,LinkedList<String> re,String temp ) {
		if(temp.length()==s.length()+3){
			String[] t=temp.split("\\.");
			for(String str:t){
				if(!isValidNum(str)){
					return ;
				}
			}
			re.add(temp);
		}
		if(temp.length()>0){
			String[] t=temp.split("\\.");
			int count=t.length;
			int last=s.length()-(temp.length()-count)-1;
			if(last>3*(4-count)||last<(4-count)){
				return;
			}
			for(int i=start+1;i<start+4&&i<s.length();i++){
				String stemp=s.substring(start+1, i+1);
				if(!isValidNum(stemp))
					return ;
				String tt=temp;
			    temp=temp+"."+stemp;
				backtrace(s,i,re,temp);
				temp=tt;
				
			}
		}
		else{
			for(int i=start;i<start+3&&i<s.length();i++){
		
			String stemp=s.substring(start, i+1);
			if(!isValidNum(stemp))//初始化最小的
				break ;
			String tt=temp;
		    temp=stemp;
			backtrace(s,i,re,temp);
			temp=tt;
		}
		}
		
	}
	public boolean isValidNum(String str){//不合法的ip地址
		  if(str.length()>3||str.length()<1){
			  return false;
		  }
		  else{
			  if(str.charAt(0)=='0'&&str.length()>1)
				  return false;
			  int count=new Integer(str);
			
			  if(count>255)
				  return false;
			  else 
				  return true;
			 
		  }
	  }
}
```