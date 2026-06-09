将s1、s2中的所有字符做异或，如果最后结果是0则为字符重排，否则不是

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        int res = 0;
        if(s1.length() != s2.length()) return false;
        for(int i = 0; i < s1.length(); i ++)
        {
            res = res ^ s1.charAt(i);
            res = res ^ s2.charAt(i);
        }
        if(res == 0) return true;
        return false;
    }
}
```
