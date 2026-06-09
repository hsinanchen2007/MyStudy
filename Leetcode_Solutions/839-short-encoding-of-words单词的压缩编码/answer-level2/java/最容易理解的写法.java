没有采用字段树，而是采用了最容易理解的写法
```
 public int minimumLengthEncoding(String[] words) {
        // 先按字符串长度进行排序
        Arrays.sort(words, (w1, w2) -> w2.length() - w1.length());

        // 然后在进行匹配的计算
        String sb = new String();
        for (String word : words) {
            if (!sb.contains(word + "#")) {
                sb = sb.concat(word + "#");
            }
        }
        return sb.length();
    }
```
