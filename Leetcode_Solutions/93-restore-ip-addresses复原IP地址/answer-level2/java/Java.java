```java
class Solution {
    List<String> res;
    public List<String> restoreIpAddresses(String s) {
        
        res = new ArrayList<String>();
        if (s.length() > 20) return res;
        helper(s, "", 0);
        return res;
    }

    void helper (String s, String cur, int len) {
        if (len == 4 && s.isEmpty()) {
            res.add(cur);
            return;
        }
        for (int k = 1; k < 4; k ++) {
            if (s.length() < k) break;
            int val =Integer.parseInt(s.substring(0, k));
            if (val > 255 || k != String.valueOf(val).length()) continue;
            helper(s.substring(k), cur + s.substring(0, k) + (len == 3 ? "" : "."), len + 1);
        }
    }
}
```