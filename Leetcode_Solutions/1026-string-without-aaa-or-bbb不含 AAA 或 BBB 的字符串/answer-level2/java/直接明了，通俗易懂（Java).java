### 解题思路
啥也不说了，直接看代码吧！

### 代码

```java
class Solution {
    public String strWithout3a3b(int A, int B) {
        if (A <= 0 && B <= 0) return "";
        else if (A <= 0) return concat(B, "b");
        else if (B <= 0) return concat(A, "a");

        String more = "";
        String less = "";

        if (A > B) {
            more = "a";
            less = "b";
        } else {
            more = "b";
            less = "a";
        }

        int left = Math.abs(A - B);

        int x = Math.min(A, B);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < x; i++) {
            // 让多的开头
            sb.append(more);
            if (left > 0) {
                sb.append(more);
                left--;
            }
            sb.append(less);
        }

        // left还有剩，直接从后面补  (例如A = 1，B = 4，上面遍历结束后left = 2)
        // (因为我们让数量多字母的开头，所以之前的sb一定是以少的字母结尾，这样就不会出现"aaa"或"bbb"的情况)
        if (left > 0) sb.append(concat(left, more));

        return sb.toString(); 
    }

    private String concat(int a, String x) {
        StringBuffer sf = new StringBuffer();
        for (int i = 0; i < a; i++) {
            sf.append(x);
        }
        return sf.toString();
    }
}
```