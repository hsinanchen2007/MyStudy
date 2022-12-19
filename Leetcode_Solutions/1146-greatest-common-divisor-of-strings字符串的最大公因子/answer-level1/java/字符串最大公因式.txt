### 解题思路
有点类似求最大公约数。
当str1.equals(str2)是既得所求。
否则将str1中的str2中替换成""
判断str1是否替换，如果没有就说明两个字符串没有‘公约数’

### 代码

```java
class Solution {
    public String gcdOfStrings(String str1, String str2) {
        // String str3=str1,str4 = str2;
        // while(!str1.equals(str2)){
        //     if(str1.length() > str2.length()){
        //         str1 = str1.replaceFirst(str2,"");
        //         if(str1 == str3){
        //             return "";
        //         }
               
        //     }else{
        //         str2 = str2.replaceFirst(str1,"");
        //         if(str2 == str4){
        //             return "";
        //         }
                
        //     } 
        // }
        // return str1;
          String str3=str1,str4 = str2;
        if(str1.equals(str2)){
            return str1;
        }
            if(str1.length() > str2.length()){
                str1 = str1.replaceFirst(str2,"");
                if(str1 == str3){
                    return "";
                }
               return gcdOfStrings(str1,str2);
            }else{
                str2 = str2.replaceFirst(str1,"");
                if(str2 == str4){
                    return "";
                }
               return gcdOfStrings(str1,str2);
            } 
        
       
    }
}
```