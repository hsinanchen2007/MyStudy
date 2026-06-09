



```
class Solution {
    public int strToInt(String str) {
        if(str==null||str.length()==0)return 0;
       int i=0;
       long ans=0;
       boolean isFu=false;
        while (i<str.length()&&str.charAt(i)==' ')i++; //过滤空格
        if (i<str.length()&&(str.charAt(i)=='+'||str.charAt(i)=='-'))  //正负号
        {
            if (str.charAt(i)=='-')isFu=true;
            i++;
        }
        for (; i <str.length()&&Character.isDigit(str.charAt(i)) ; i++) {

            ans=  ans*10+  str.charAt(i)-'0';
            
            long temp_ans=isFu?-ans:ans;
             
                  if (temp_ans<=Integer.MIN_VALUE)return Integer.MIN_VALUE;
                  if (temp_ans>=Integer.MAX_VALUE)return Integer.MAX_VALUE;
                  
        }
           return  (int) (isFu? -ans:ans);
    }
}
```
