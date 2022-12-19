### 解题思路
一遍一遍递归下去就好了，核心思想就是定义位置坐标，最后再处理最后一次数据就好了。

### 代码

```java
class Solution {
    public String countAndSay(int n) {
        if (n < 1 || n > 30) {
            throw new RuntimeException("越界了");
        }
        String start = "1";
        if (n == 1) {
            return start;
        }
        for (int i = 1; i < n; i++) {
            start = this.deal(start);
        }
        return start;
    }

    private String deal(String v) {
        int start = 0;
        char p = v.charAt(0);
        StringBuffer r = new StringBuffer();
        for (int i = 1; i < v.length(); i++) {
            if (p != v.charAt(i)) {
                r.append(i - start).append(p);
                p = v.charAt(i);
                start = i;
            }
        }
        if (v.length() > start) {
            r.append(v.length() - start).append(p);
        }
        return r.toString();
    }
}
```