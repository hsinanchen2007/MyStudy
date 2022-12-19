### 解题思路
三行解决

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        String s = num + "";

        s = s.replaceFirst("6", "9");

        return Integer.valueOf(s);
    }
}
```