# Java
两种方法都是一个原理：字符串中是否有“**abc**”，如有，将其**replace**为**“”**，以此循环，最后判断是否满足条件
**第一种方法**：
```
/**
 * @Author-- Skipper
 */
public class Solution2 {
    public boolean isValid(String S) {
        String[] str = S.split("abc");
        while (str.length > 1) {
            StringBuilder tmp = new StringBuilder();
            for (String aStr : str) {
                tmp.append(aStr);
            }
            str = tmp.toString().split("abc");
        }
        return str.length == 0;
    }
}
```
**第二种方法**：
```
/**
 * @Author-- Skipper
 */
class Solution {
    public boolean isValid(String S) {
        while (S.length() > 0 && S.contains("abc"))
            S = S.replace("abc", "");
        return  S.equals("") ;
    }
}
```

