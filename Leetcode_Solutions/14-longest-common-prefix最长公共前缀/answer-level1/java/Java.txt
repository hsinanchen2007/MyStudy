### 解题思路


### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
         if(strs.length==0)
              return "";
          String res=strs[0];
          for(int i=1;i<strs.length;i++)
          {
             
              while(res.length()>0){
                    if(strs[i].indexOf(res)!=0)
                     {
                        res=res.substring(0,res.length()-1);
                        continue;
                     }
                     else
                     {
                         break;
                     }
              }
              if (res.length()==0) return "";
          }
          return res;
        }
    }

```