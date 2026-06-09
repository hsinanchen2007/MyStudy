### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
      //如果x小于0的话   就是负数，负数就返回false  
     if (x<0){
          return false;
      }
      String gg=Integer.toString(x); //将int 类型转成string类型
        for (int i = 0; i <gg.length()/2 ; i++) {  //每次循环字符串长度的一半
            if (gg.charAt(i)!=gg.charAt(gg.length()-i-1)){
                return false;
            }
        }
      return  true;
    
    }
}
```