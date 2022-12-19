```Java
class Solution{
	public String addStrings(String num1,String num2){
		 StringBuilder sb=new StringBuilder();
		 int len1=num1.length();
		 int len2=num2.length();
		 String one="";
		 String two="";
		 if(len1>len2){
		 	one=num1;
		 	two=num2;
		 }else{
		 	one=num2;
		 	two=num1;
		 }
		 len1=one.length();
		 len2=two.length();
		 int carry=0,sum=0,i=0,j=0;
		 for(i=len1-1,j=len2-1;i>=0&&j>=0;){
		 	sum=one.charAt(i)-'0'+two.charAt(j)-'0'+carry;
		 	carry=sum/10;
		 	sb.append(sum%10);
		 	i--;j--;
		 }

		 while(i>=0){
		 	sum=one.charAt(i)-'0'+carry;
		 	carry=sum/10;
		 	sb.append(sum%10);
		 	i--;
		 }
		 if(carry==1)
		 	sb.append(1);
		 return sb.reverse().toString();
	}
}
```