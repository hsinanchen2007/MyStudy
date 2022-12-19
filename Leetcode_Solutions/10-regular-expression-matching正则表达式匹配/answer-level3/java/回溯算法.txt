### 代码

```java
class Solution {
    public boolean isMatch(String s, String p) {
        if(p.isEmpty()) return s.isEmpty();
        boolean first_Match = !s.isEmpty() &&
            ((s.charAt(0) == p.charAt(0)) || (p.charAt(0) == '.'));
        //p只能是第二位为*
        if(p.length() >= 2 && p.charAt(1) == '*'){
            //第一位没匹配第二位为*,表明*代表前面字符出现0次
            //第一位匹配了，并且第二位为*
            return (isMatch(s,p.substring(2)))||
                    (first_Match && isMatch(s.substring(1),p));
        }else{
            return first_Match && isMatch(s.substring(1),p.substring(1));
        }
    }
}
```