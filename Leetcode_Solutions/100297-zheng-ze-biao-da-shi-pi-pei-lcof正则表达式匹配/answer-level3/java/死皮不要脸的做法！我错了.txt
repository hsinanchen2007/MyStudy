### 解题思路

```
这种脸皮厚的做法我也很无奈啊！哈哈哈！我也知道肯定要用数组捣鼓半天
不过说实话，动态规划真的比Java自带的这两个玩意儿实现得好！
我要去学习其他大佬的动态规划了！哈哈哈
```

### 代码

```java
import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Solution {
    public boolean isMatch(String s, String p) {
        String regx =p;
        Pattern pattern = Pattern.compile(regx);
        Matcher m = pattern.matcher(s);
        return m.matches();
    }
}

```