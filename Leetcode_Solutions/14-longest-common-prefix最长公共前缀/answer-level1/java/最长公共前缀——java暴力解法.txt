### 解题思路
此处撰写解题思路
取字符串组strs中最小字符串str，以防字符串超出
从最长递减到最短截取str,遍历strs判断是否最长公共前缀
if(true)则直接返回最长公共前缀
### 代码

```java
class Solution {

   public String longestCommonPrefix(String[] strs) {
         int len = strs.length;
        if(len==0){
            return "";
        }
        String str = strs[0];
        for(String s:strs){
            str = s.length()<str.length()?s:str;
        }
        int str_len = str.length();
        for(int i=str_len;i>0;i--){
            for(int k=0;k<len;k++){
                if(!(strs[k].substring(0,i).equals(str.substring(0,i)))){
                    break;
                }else if(k==len-1){
                    return str.substring(0,i);
                }
            }
        }
        return "";
    }
}
```