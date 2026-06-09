### 解题思路
无论加减都是加。不过是负数而已
### 代码

```java
class Solution {
   public String fractionAddition(String exp) {
		 //第一步，将字符串转换为分数"-1/2+1/2+1/3"
		 int[] fenshu={0,1};
		 Stack<String> stack=new Stack<String>();
		 for(int i=0;i<exp.length();i++){
			 char ch=exp.charAt(i);
			 if(ch=='/')
				 stack.push(exp.substring(i,i+1));
			 else if(ch>='2'&&ch<='9'){
				 stack.push(exp.substring(i,i+1));
			  }
			 else if(ch=='1'){
				 if(i<exp.length()-1&&exp.charAt(i+1)=='0')
				 { 
					 stack.push(exp.substring(i,i+2));
				     i++;
				 }
				 else
					 stack.push(exp.substring(i,i+1));
			 }else{
				 if(i==0){
					 stack.push(exp.substring(i,i+1));
				 }
				 else{
			     int[] temp=toFenshu(stack);
			     fenshu=cacul(temp,fenshu);
			     stack.removeAllElements();
			     if(ch=='-'){
			    	 stack.push(exp.substring(i,i+1));
				 }
			 }
				 }
		 }
		 int[] t=toFenshu(stack);
		 fenshu=cacul(t,fenshu);
		int k=findMaxyueshu(Math.abs(fenshu[0]),Math.abs(fenshu[1]));
		fenshu[0]=fenshu[0]/k;
		fenshu[1]=fenshu[1]/k;
		String re=fenshu[0]+"/"+fenshu[1];
		return re;
	    }
	 public int[] toFenshu(Stack<String> stack){
		 int[] temp=new int[2];
	     String strTemp1="";
	     for(String s:stack)
	    	 strTemp1=strTemp1+s;
	     
	     String[] strArr=strTemp1.split("/");
	     temp[0]=new Integer(strArr[0]);
	     temp[1]=new Integer(strArr[1]);
         
	     return temp;
	 }
	private int[] cacul(int[] temp, int[] fenshu) {
		int t1=temp[0],f1=fenshu[0];
		int t2=temp[1],f2=fenshu[1];
		if(f1==0)
			return temp;
		int[] re=new int[2];
		re[0]=t1*f2+t2*f1;
		re[1]=t2*f2;
		if(re[0]%re[1]==0){
			re[0]=re[0]/re[1];
			re[1]=1;
	}
		return re;
	}
	private int findMaxyueshu(int i, int j) {
		int min=Math.min(i, j);
		int max1=1;
		for(int k=1;k<=min;k++){
			if(i%k==0&&j%k==0)
				max1=Math.max(max1, k);
		}
		return max1;
	}
}
```