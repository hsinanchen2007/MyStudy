### 解题思路
异或运算，相同为零不同为一；

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
  if (s1.length()!=s2.length())
            return false;
        int length=s1.length();
        
        int result=0;
        
        for (int i=0;i<length;i++)
            result^=s1.charAt(i);
        for (int i=0;i<length;i++)
            result^=s2.charAt(i);
        
        if (result==0)
            return true;
        return false;
    }
}
```