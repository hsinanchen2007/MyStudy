### 解题思路
以第一个字符串为基字符串，从第二个字符串开始遍历，如果某个字符出现的次数为数组的长度，则把这个字符存到字符串中

### 代码

```java
class Solution {
    public String longestCommonPrefix(String[] strs) {
     String num="";
     int min=1000,flag=0;
     if(strs.length==1){
         return strs[0];
     }
     for(int i=0;i<strs.length;i++){
      if(min>strs[i].length())
        min=strs[i].length();
     }
         
         for(int j=0;j<min;j++){  
             for(int k=1;k<=strs.length-1;k++){
      if(strs[0].charAt(j)==strs[k].charAt(j)){
          flag++;
      }
       else{
         return num;
      }
    
      if(flag==strs.length-1){
          num+=strs[0].charAt(j);
          flag=0;
      }
     
     }
         }
     return num;
    }
}
```