
```java
class Solution {
    public boolean isUnique(String astr) {
        // You should first ask your interviewer if the string is an ASCII string or a Unicode string
        // Asking this question will show an eye for detail and a solid foundation in computer science
        // 位运算 bit vector
        int mask = 0, n = astr.length();
        for (int i = 0; i < n; i++) {
            int move = astr.charAt(i) - 'a';
            if ((mask & (1 << move)) != 0) return false;
            mask |= (1 << move);
        }
        return true;
    }
}
```
