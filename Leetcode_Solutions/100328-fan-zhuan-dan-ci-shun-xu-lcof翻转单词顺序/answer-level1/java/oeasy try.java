### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseWords(String s) {
       
	 String[] re=s.split(" ");
		 String res="";
		 for(int i=re.length-1;i>=0;i--){
			 if(!re[i].equals("")&&i!=0){
				 res=res+re[i]+" ";
			 }
			 else if(i==0&&!re[0].equals(""))
				 res=res+re[0];
		 }
         if(res.equals(""))
			 return res;
	   else  if(res.substring(res.length()-1, res.length()).equals(" "))
			res=res.substring(0, res.length()-1);
		 
		return res;

    }
}
```