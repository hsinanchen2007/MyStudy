### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
       if(x<0)return false;
       else{
           String s = String.valueOf(x);
           for(int i=0;i<s.length()/2;i++){
               if(s.charAt(i)!=s.charAt(s.length()-1-i))
               return false;
           }
           return true;
       }
       

    }
}
```