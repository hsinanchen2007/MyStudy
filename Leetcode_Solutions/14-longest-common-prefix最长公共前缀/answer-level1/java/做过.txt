### 解题思路
en 没啥好写的，打败这么点人

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0) return "";
        String ans="";
        ans=strs[0];
        for(int i=0;i<strs.length;i++){
          int j=0;
            for(;j<strs[i].length()&&j<ans.length();j++){
                if(strs[i].charAt(j)!=ans.charAt(j)){
                    break;
                }
            }
            ans=ans.substring(0,j);
            if(ans==""){
                return ans;
            }
            
        }
        return ans;

    }
}
```