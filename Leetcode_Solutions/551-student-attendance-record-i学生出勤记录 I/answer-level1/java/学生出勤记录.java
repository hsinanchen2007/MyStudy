### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean checkRecord(String s) {
        if(s.length()<=1)
        return true;
      int flag=0;
      for(int i=1;i<s.length()-1;i++){
          if(s.charAt(i)=='A')
          flag++;
          if(s.charAt(i)=='L'&&s.charAt(i+1)=='L'&&s.charAt(i-1)=='L')
          return false;
          if(flag>1)return false;
      }
      if(s.charAt(s.length()-1)=='A')
      flag++;
      if(s.charAt(0)=='A')
      flag++;
      return flag<=1;
    }
}
```