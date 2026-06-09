第一次遍历s，使用桶来记录出s中字母的个数。

第二次遍历t，如果存在t中某个字母的频次比s中少的情况，则会出现桶中数字小于0的情况，直接返回false

```java
class Solution {
    public boolean isAnagram(String s, String t) {
        int[] b = new int[26];
        for(int i = 0; i < s.length(); i++) b[s.charAt(i) - 'a']++;
        for(int i = 0; i < t.length(); i++) if(--b[t.charAt(i) - 'a'] < 0) return false;
        return s.length() == t.length();
    }
}
```