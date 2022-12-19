### 解题思路
使用String类的replace方法即可

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        return s.replace(" ","%20");
    }
}
```