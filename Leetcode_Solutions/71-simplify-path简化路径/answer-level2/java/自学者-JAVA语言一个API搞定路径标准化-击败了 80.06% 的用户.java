### 解题思路
* 堆栈思路但是实现起来不太好编写

### 代码

```java
import java.nio.file.*;
class Solution {
    public String simplifyPath(String path) {
        return Paths.get(path).normalize().toString();
    }
}
```