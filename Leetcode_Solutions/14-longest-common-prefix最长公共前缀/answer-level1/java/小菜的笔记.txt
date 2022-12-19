### 解题思路
此处撰写解题思路
注意寻找最长公共前缀是先将第一个字符串初始化为最长前缀，再依次与后边字符串比较。

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
        if(strs.length==0)return "";
       // int l=zuixiao(strs);
        String s1=strs[0];
       // StringBuilder sb=new StringBuilder();
        for(int j=1;j<strs.length;j++){
            int i=0;
            for(;i<s1.length()&&i<strs[j].length();i++){
                if(s1.charAt(i)!=strs[j].charAt(i)){
                    break;
                    
                }
                //else sb.append(strs[0].charAt(i));
               
            }
            s1=s1.substring(0,i);
            if(s1.length()==0)return "";
            
        }
        return s1;

    }
   
}
```