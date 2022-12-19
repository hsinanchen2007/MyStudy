### 解题思路
用replace后的长度做判断即可

### 代码

```java
class Solution {
    public boolean isUnique(String astr) {
        for (int i=0;i<astr.length();i++){
            String s=astr;
            s=s.replace(String.valueOf(s.charAt(i)),"");
            if (s.length()!=astr.length()-1)
                return false;
        }
        return true;
    }
}
```