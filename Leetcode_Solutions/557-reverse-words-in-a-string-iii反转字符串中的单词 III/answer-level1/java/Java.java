```
class Solution {
    public String reverseWords(String s) {
        String s1[] = s.split(" ");
        StringBuilder sb = new StringBuilder();

        String r = "";
        for (int i = 0; i < s1.length; i++) {
            sb.append(s1[i]);
            if (i != s1.length - 1) {
                r += sb.reverse() + " ";
            } else {
                r += sb.reverse();
            }

            sb.delete(0, sb.length());

        }
        return r;
    }
}
```
