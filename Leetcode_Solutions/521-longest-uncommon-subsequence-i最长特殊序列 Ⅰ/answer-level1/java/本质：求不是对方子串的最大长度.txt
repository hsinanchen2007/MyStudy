```java
class Solution {
    public int findLUSlength(String a, String b) {
        int res = -1;
        if(!a.equals(b))
            res = a.length()>b.length()?a.length():b.length();
        return res;
    }
}
```