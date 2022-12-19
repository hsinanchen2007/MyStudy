### 解题思路
1. 直接调用`Java`中`String`类自带的`replace()`方法；

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        return s.replace(" ", "%20");
    }
}
```