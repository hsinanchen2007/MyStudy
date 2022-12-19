### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countSegments(String s) {
         boolean Noletter=true;
         int count=0;
         for(int i=0;i<s.length();i++){
             if(s.charAt(i)==' ')
              Noletter=true;
              if(s.charAt(i)!=' '&&Noletter==true){
                 count++;
                 Noletter=false;
              }
         }
         
         return count;
    }
}
```