### 解题思路
转为string，一个for循环判断

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
       String s= x+"";
       int m=s.length();
       for(int i=0;i<=m/2;i++){
           if(s.charAt(i)!=s.charAt(m-i-1)){
               return false;
           }


       }
       return true;

    }
}
```