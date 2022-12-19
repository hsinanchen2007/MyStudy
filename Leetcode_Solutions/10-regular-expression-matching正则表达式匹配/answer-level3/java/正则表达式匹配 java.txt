可以用String.matches()
```
class Solution {
    public boolean isMatch(String s, String p) {
        if (s == null) {
            if (p == null) {
                return true;
            } else {
                return false;
            }
        }
        if (s.equals(p)) {
            return true;
        }
        return s.matches(p);
    }
}
```