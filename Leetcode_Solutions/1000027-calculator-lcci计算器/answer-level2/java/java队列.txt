两个队列存储数字 和+ -   
* / 用另外的函数直接计算值
没有多写一个函数  所以代码很乱很乱 见谅- -
```
class Solution {
   public int calculate(String s) {
		 s=s.trim();
      Queue<Integer> queue=new LinkedList<Integer>();
      Queue<Character> queue2=new LinkedList<Character>();
      int res=0;
      for (int i = 0; i < s.length(); i++) {
    		char a=s.charAt(i);
    	    if(a==' ') {continue;}
			if(a=='+'||a=='-') {
				queue.add(res);queue2.add(a);res=0;continue;
			}
			if(a=='*') {
				int res2=0;boolean flag=false;
				for (int j = i+1; j < s.length(); j++) {
					a=s.charAt(j);if(a==' ') {continue;}
					if(a=='+'||a=='-'||a=='*'||a=='/') {i=j-1;break;}
					  res2*=10;res2+=a-'0';
					  if(j==s.length()-1) {flag=true;}//证明是最后一个
				}
				
				res=res*res2;
				if(flag) {break;}continue;
			}
			if(a=='/') {
				int res2=0;boolean flag=false;
				for (int j = i+1; j < s.length(); j++) {
					a=s.charAt(j);if(a==' ') {continue;}
					if(a=='+'||a=='-'||a=='*'||a=='/') {i=j-1;break;}
					  res2*=10;res2+=a-'0';
					  if(j==s.length()-1) {flag=true;}//证明是最后一个
				}
				
				res=res/res2;
				if(flag) {break;}continue;
			}
		    res*=10;res+=a-'0';
		    
	}
      queue.add(res);
    
      int result=queue.remove();
      while(!queue.isEmpty()) {
    	  int num=queue.remove();
    	  char fu=queue2.remove();
    	  if(fu=='-') {result-=num;}
    	  if(fu=='+') {result+=num;}
      }
      return result;
     
      
	    }
}
```
