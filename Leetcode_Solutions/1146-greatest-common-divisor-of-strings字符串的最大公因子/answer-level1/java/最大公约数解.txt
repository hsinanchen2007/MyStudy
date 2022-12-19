### 解题思路
通过两个长度相减求两个字符串长度的最大公约数，按照子串判断是否符合

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        String sub = "";
        if(str1.length() ==0 || str2.length() == 0){
            return sub;
        }

        int max;
        int min;
        if(str1.length() > str2.length()){
            max = str1.length();
            min = str2.length();
        }else{
            max = str2.length();
            min = str1.length();
        }
        
        
        while(max > min){
            if(max- min > min){
                max = max-min;
            }else{
                int temple = max-min;
                max = min;
                min = temple;
            }
        }
        
        sub = str1.substring(0,max);
        for(int i = max;i<str1.length();i+=max){
            if(!str1.substring(i,i+max).equals(sub)){
                return "";
            }
        }

        for(int i = 0;i<str2.length();i+=max){
            if(!str2.substring(i,i+max).equals(sub)){
                return "";
            }
        }

        return sub;
    }
}
```