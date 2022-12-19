### 解题思路
跟1ms的大神思路相同 可参照的大神的代码来

### 代码

```java
import java.util.regex.Pattern;

class Solution {
    public String longestCommonPrefix(String[] strs) {
        
        List<String> list=new ArrayList<String>();
        String result="";
        String upres="";
        boolean flag=false;

        if(strs.length==0 || strs ==null){
            return "";
        }

        for(int j=1;j<strs[0].length()+1;j++){
                String temp=strs[0].substring(0,j);
                list.add(temp);
        }

          for(String s:list) {

             String pattern = s+".*";

              for (int i = 1; i < strs.length; i++) {
                  if (!Pattern.matches(pattern, strs[i])) {
                      flag=true;
                      break;
                  }
              }

              if(flag){
                  break;
              }

              result=s;

          }

        return result;
    }
}
```