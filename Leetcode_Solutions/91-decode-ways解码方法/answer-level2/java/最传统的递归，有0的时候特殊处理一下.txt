### 解题思路
最传统的递归，有0的时候特殊处理一下
### 代码

```java
class Solution {
    public int numDecodings(String s) {
        if (!s.contains("0")) {
            return fun(s);
        }
        s = s.replaceAll("10", "A");
        s = s.replaceAll("20", "A");
        if (s.contains("0")) {
            return 0;
        }
        String[] as = s.split("A");
        int res = 1;
        for (String a : as) {
            res *= fun(a);
        }
        return res;
    }

    private int fun(String s) {
        if (s.length() < 2) {
            return 1;
        }
        if (s.length() == 2) {
            return s.compareTo("26") <= 0 ? 2 : 1;
        }
        String sub = s.substring(0, 2);
        if (sub.compareTo("26") <= 0) {
            return fun(s.substring(1)) + fun(s.substring(2));
        } else {
            return fun(s.substring(1));
        }
    }
}
```