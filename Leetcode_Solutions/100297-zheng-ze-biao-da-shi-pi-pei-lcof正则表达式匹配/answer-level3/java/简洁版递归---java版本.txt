```java
class Solution {
    public boolean isMatch(String text, String pattern) {
        if(pattern == null || pattern.length() == 0) return text == null || text.length() == 0;
        boolean first = (text != null && text.length() != 0) && (pattern.charAt(0) == text.charAt(0) || pattern.charAt(0) == '.');
        if(pattern.length() >=2 && pattern.charAt(1) == '*') return isMatch(text,pattern.substring(2)) || (first && isMatch(text.substring(1),pattern));
        else return first && isMatch(text.substring(1),pattern.substring(1));
    }
}
```