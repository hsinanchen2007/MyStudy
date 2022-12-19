### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String reverseStr(String s, int k) {
        String num="";int count=0;
      for(int i=0;i<s.length();i+=2*k){
          if(s.length()-i>=2*k){
           for(int j=i+k-1;j>=i;j--)
           num+=s.charAt(j);
           for(int j=i+k;j<i+2*k;j++)
           num+=s.charAt(j);
           count++;
          }
      }
      if(s.length()-count*2*k<k){
         
          for(int i=s.length()-1;i>=2*k*count;i--){
          num+=s.charAt(i);}
      }
      else if(s.length()-count*2*k>=k&&s.length()-count*2*k<2*k){
          for(int i=2*k*count+k-1;i>=2*k*count;i--)
          num+=s.charAt(i);
          for(int i=2*k*count+k;i<s.length();i++)
          num+=s.charAt(i);
      }
      return num;
    }
}
```