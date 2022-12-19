### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        int ilen = p.length();
        List<Integer> list = new LinkedList<>();
        if (s.compareTo(p) == 0) {
            list.add(0);
            return list;
        }
        for (int i = 0; i <= s.length() - p.length(); i++) {
            String str = s.substring(i, i + ilen);
            if (isOK(str, p)) {
                list.add(i);
            }
        }
        return list;
    }

    public boolean isOK(String a, String b) {
        if (a.length() != b.length()) {
            return false;
        }
        int[] ar = new int[26];
        int[] br = new int[26];
        for (int i = 0; i < a.length(); i++) {
            ar[a.charAt(i) - 'a']++;
            br[b.charAt(i) - 'a']++;
        }
        for (int i = 0; i < 26; i++) {
            if (ar[i] != br[i]) {
                return false;
            }
        }
        return true;
    }
}
```