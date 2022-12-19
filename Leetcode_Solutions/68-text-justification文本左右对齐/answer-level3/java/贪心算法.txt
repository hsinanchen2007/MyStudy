### 解题思路
这道题用贪心算法非常简单， 不知道是不是出题人想要的结题方案。

### 代码

```java
class Solution {
    private int maxWidth;

    public List<String> fullJustify(String[] words, int maxWidth) {
        if (words == null || words.length == 0) return null;
        
        this.maxWidth = maxWidth;
        List<String> result = new LinkedList<>();
        List<String> rowWord = new LinkedList<>();
        int len = 0;
        for (int i = 0; i < words.length; i++) {
            if (words[i].length() > maxWidth) return null;
            if (len + words[i].length() > maxWidth) {
                result.add(justify(rowWord));
                len = 0;
            }
            rowWord.add(words[i]);
            len += words[i].length();
            len++;
        }
        if (!rowWord.isEmpty()) {
//            result.add(String.format(String.format("%%-%ds", maxWidth), String.join(" ", rowWord)));
            StringBuilder last = new StringBuilder();
            for (int i = 0; i < rowWord.size() - 1; i++) {
                last.append(rowWord.get(i)).append(" ");
            }
            last.append(rowWord.get(rowWord.size()-1));
            while (last.length() < maxWidth) last.append(" ");
            result.add(last.toString());
        }
        return result;
    }

    private String justify(List<String> words) {
        int total = words.size();
        StringBuilder sb = new StringBuilder();
        if (total == 1) {
            sb.append(words.remove(0));
            while (sb.length() < maxWidth) sb.append(" ");
            return sb.toString();
        }
        int len = 0;
        for (String word : words
        ) {
            len += word.length();
        }
        int quotient = (maxWidth-len) / (total - 1);
        int remainder = (maxWidth-len) % (total - 1);
        StringBuilder blank = new StringBuilder();
        for (int i = 0; i < quotient; i++) {
            blank.append(" ");
        }

        for (int i = 0; i < total - 1; i++) {
            sb.append(words.remove(0)).append(blank.toString());
            if (remainder > 0) {
                sb.append(" ");
                remainder--;
            }
        }
        sb.append(words.remove(0));
        return sb.toString();
    }
}
```