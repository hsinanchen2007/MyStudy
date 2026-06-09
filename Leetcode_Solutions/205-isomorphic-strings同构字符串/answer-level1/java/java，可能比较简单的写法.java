```java
class Solution {
    public boolean isIsomorphic(String s, String t) {
        char[] ch1 = s.toCharArray();
        char[] ch2 = t.toCharArray();
        int len = s.length();
        for (int i = 0; i < len; i++) {
            if(s.indexOf(ch1[i]) != t.indexOf(ch2[i])){
                return false;
            }
        }
        return true;
    }
}
```
字符串中，同一个位置的字符在本串中第一次出现的位置相同。我简单解释一下，本题判定为false有这些个情况，我们假设拿s串和t串作对比
1.s串中相同的字符，对应的t串中的字符并不相等
2.s串中不同的字符，对应的t串中的字符却是相等的
所以判断的关键点就是相同的字符要对应相同的字符，那么相同字符处于后位置的字符的第一次出现的位置就应该相同。
所以我们在判断时，只需要判断两个字符串同位置的字符是否相同即可。
