### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public String boldWords(String[] words, String S) {
        boolean[] isBold = new boolean[S.length()];
        for(String word : words) {
            int n = S.indexOf(word, 0);
            while(n != -1) {
                for(int i = n; i < n + word.length(); i++) {
                    isBold[i] = true;
                }
                n = S.indexOf(word, n + 1);
            }
        }
        StringBuilder s = new StringBuilder();
        if(isBold[0]) {
            s.append("<b>");
        }
        int i = 0;
        for(; i < isBold.length - 1; i++) {
            s.append(S.charAt(i));
            if(isBold[i] && !isBold[i+1]) {
                s.append("</b>");
            }
            if(!isBold[i] && isBold[i+1]) {
                s.append("<b>");
            }
        }
        if(i == isBold.length -1) {
            s.append(S.charAt(i));
            if(isBold[i]) {
                s.append("</b>");
            }
        }
        return s.toString();
    }
}
```