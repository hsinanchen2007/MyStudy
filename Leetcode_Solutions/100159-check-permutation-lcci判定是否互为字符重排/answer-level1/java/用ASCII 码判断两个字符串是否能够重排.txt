### 解题思路
每个字符的ASCII码是唯一的,可以将字符串的字符ASCII相加,判断两个串的ASCII的加值是否相等

### 代码

```java
class Solution {
    public boolean CheckPermutation(String s1, String s2) {
        if(s1.length()!=s2.length()){
            return false;
        }

        int s1Asci = 0;
        int s2Asci = 0;
        for(int i=0;i<s1.length();i++){
            s1Asci=s1Asci+s1.charAt(i);
            s2Asci=s2Asci+s2.charAt(i);
        } 

        if(s1Asci!=s2Asci){
            return false;
        }

        return true;
    }
}
```