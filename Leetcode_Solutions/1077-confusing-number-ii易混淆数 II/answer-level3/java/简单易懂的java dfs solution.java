
```java
class Solution {
    int res = 0;
    String nums = "01689";
    String n;
    public int confusingNumberII(int N) {
        n = "" + N;
        helper("");
        return res;
    }

    void helper(String cur) {
        if (cur.length() > n.length() || cur.length() == n.length() && cur.compareTo(n) > 0) return;
        if (cur.length() > 1 && cur.charAt(0) == '0') return;
        StringBuilder sb = new StringBuilder();
        sb.append(cur);
        sb.reverse();
        for (int i = 0; i < sb.length(); i ++) {
            if (sb.charAt(i) == '6') {
                sb.setCharAt(i, '9');
            } else if (sb.charAt(i) == '9') {
                sb.setCharAt(i, '6');
            }
        }
        if (!sb.toString().equals(cur)) res ++;
        for (int i = 0; i < nums.length(); i ++) {
            helper(cur + nums.substring(i, i + 1));
        }
    }
}```
