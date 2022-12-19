```java
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        for (int i = 0; i < words.length - 1; i++) {
            String s = words[i];
            if (com(s, words[i + 1], order) > 0) {
                return false;
            }
        }
        return true;
    }

    private int com(String s1, String s2, String order) {
        char[] a1 = s1.toCharArray();
        char[] a2 = s2.toCharArray();
        int len1 = a1.length;
        int len2 = a2.length;
        int lim = Math.min(len1, len2);
        int k = 0;
        while (k < lim) {
            char c1 = a1[k];
            char c2 = a2[k];
            if (c1 != c2) {
                return order.indexOf(c1) - order.indexOf(c2);
            }
            k++;
        }
        return len1 - len2;
    }
}
```