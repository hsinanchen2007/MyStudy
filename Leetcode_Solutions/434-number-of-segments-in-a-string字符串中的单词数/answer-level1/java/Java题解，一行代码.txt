```
class Solution {
    public int countSegments(String s) {
        return s.trim().equals("")?0:s.trim().split("\\s++").length;
    }
}
```
