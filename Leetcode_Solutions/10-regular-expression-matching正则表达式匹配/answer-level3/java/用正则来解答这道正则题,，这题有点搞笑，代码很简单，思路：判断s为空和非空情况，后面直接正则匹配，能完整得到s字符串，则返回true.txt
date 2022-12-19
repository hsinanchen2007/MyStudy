### 解题思路
此处撰写解题思路

### 代码

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Solution {
    public boolean isMatch(String s, String p) {
        if (p.equals(".*")) {
            return true;
        }
        boolean judge = Pattern.matches("^(.\\*)*",p);
        if(s.length()==0){
            if(judge){
                return true;
            }else {
                return false;
            }
        }
        Pattern pat = Pattern.compile(p);
        Matcher matcher = pat.matcher(s);
        String getRes = "";
        if (matcher.find()) {
            getRes = matcher.group();
        }
        if (getRes.equals(s)) {
            return true;
        } else {
            return false;
        }

    }
    
}
```