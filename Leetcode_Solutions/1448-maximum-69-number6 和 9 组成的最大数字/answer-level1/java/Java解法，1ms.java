执行用时 :1 ms, 在所有 Java 提交中击败了96.40%的用户
内存消耗 :33.1 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    public int maximum69Number (int num) {
        StringBuilder s = new StringBuilder(String.valueOf(num));
        int a = s.indexOf("6");
        if (a > -1) {
            s.setCharAt(a,'9');
            return Integer.parseInt(s.toString());
        } else {
            return Integer.parseInt(s.toString());
        }
    }
}
```