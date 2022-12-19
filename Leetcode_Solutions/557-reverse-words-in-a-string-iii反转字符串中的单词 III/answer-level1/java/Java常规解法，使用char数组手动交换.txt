```
class Solution {
    public String reverseWords(String s) {
        char[] c = s.toCharArray();
        s += ' ';
        for (int start = 0, space = 0; space < s.length(); space++) {
            if (s.charAt(space) != ' ') {
                continue;
            }
            for (int end = space - 1; start < end; start++, end--) {
                char temp = c[start];
                c[start] = c[end];
                c[end] = temp;
            }
            start = space + 1;
        }
        return new String(c);
    }
}
```
