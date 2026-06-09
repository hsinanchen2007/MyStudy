```Java
public int minimumLengthEncoding(String[] words) {
    // 按长度排序
    Arrays.sort(words, (o1, o2) -> o2.length() - o1.length());
        
    int res = 0;
        
    Set<String> set = new HashSet<>();
        
    for (String word: words) {
        if (!set.contains(word)) {
            res += (word.length() + 1);
            for (int i = 0; i < word.length(); i++) {
                set.add(word.substring(i));
            }
        }
    }
    return res;
}
```
