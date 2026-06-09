### 解题思路
strs[0]做为基准，依次比较。要考虑好特殊情况

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
      
      if(strs.length==0)
        return "";
      for(int i=0;i<strs.length;i++){
          if(strs[i].length()==0)
            return "";
      }  
      String result="";
      String str1=strs[0];
      for(int i=0;i<str1.length();i++){
          char char_i = str1.charAt(i);
          for(int j=1;j<strs.length;j++){
              if(strs[j].length()<=i||strs[j].charAt(i)!=char_i){
                  return result;
              }
          }
          result+=char_i;
      }
        return result;
    }  
}
```