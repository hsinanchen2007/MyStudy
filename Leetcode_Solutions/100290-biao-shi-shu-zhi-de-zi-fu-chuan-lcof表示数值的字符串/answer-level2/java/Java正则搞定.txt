用Java正则搞定，不过这正则写了半小时，各种复杂场景。。。
```
import java.util.regex.*;
class Solution {
    public boolean isNumber(String s) {
        return Pattern.matches("\\s*[+-]?((\\d+\\.?)|(\\d*\\.\\d+))([eE][+-]?\\d+)?\\s*", s);
    }
}
```
