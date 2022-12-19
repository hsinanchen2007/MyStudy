### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public void reverseString(char[] s) {

      char a  ;
      if(s.length % 2 != 0){
      for(int i = 0, j = s.length-1; i < s.length / 2 && j > s.length / 2 ; i++, j--){
              a=s[i];
              s[i] = s[j];
              s[j] = a;
      }
    }
    else{
         for(int i = 0, j = s.length-1; i <= s.length / 2 && j >= s.length / 2 ; i++, j--){
              a=s[i];
              s[i] = s[j];
              s[j] = a;
         }
    }
    }
}
```天啊，这是我第一次作对啊，太感动了呜呜呜