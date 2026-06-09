### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
       int len=astr.length();
         StringBuilder s=new StringBuilder();
         for(int i=0;i<255;i++){
             s.append('0');
         }
       for(int i=0;i<astr.length();i++){
           int index=astr.charAt(i);
           if(s.charAt(index)=='1'){
               return false;
           }
           s.setCharAt(index,'1');
       }
        return true;
    }
}
```