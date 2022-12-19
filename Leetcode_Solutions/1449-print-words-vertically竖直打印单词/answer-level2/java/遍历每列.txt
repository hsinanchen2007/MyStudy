**思路**
1. 先求所有单词的最长的那个单词的长度，假设为maxLen；
2. 列遍历[0, maxLen)，然后遍历每个单词，取出每个单词对应列的字符，若当前的列超出单词的长度，则用空格替代；
3. 其中，题目说了要去除尾随空格（注意，不能前后空格，不能直接trim），因此，每次处理完一列就处理一下尾随空格即可。

```java
    // 删除尾随空格
    private String removeSuffixSpaces(String str) {
        StringBuilder sb = new StringBuilder();
        boolean begin = false;
        for (int i = str.length() - 1; i >= 0; i--) {
            if (str.charAt(i) != ' ') {
                begin = true;
            }

            if (begin) {
                sb.append(str.charAt(i));
            }
        }

        return sb.reverse().toString();
    }

    public List<String> printVertically(String s) {
        String[] str = s.split(" ");
        int wordLen = str.length;

        int maxLen = 0;
        for (String word : str) {
            maxLen = Math.max(maxLen, word.length());
        }

        List<String> ansList = new ArrayList<>();
        for (int j = 0; j < maxLen ;j++) {
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < wordLen; i++) {
                if (str[i].length() <= j) {
                    sb.append(' ');
                } else {
                    sb.append(str[i].charAt(j));
                }
            }

            ansList.add(removeSuffixSpaces(sb.toString()));
        }

        return ansList;
    }
```