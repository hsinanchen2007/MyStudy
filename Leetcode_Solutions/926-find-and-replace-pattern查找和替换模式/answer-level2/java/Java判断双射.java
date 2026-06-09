```
public List<String> findAndReplacePattern(String[] words, String pattern) {
    List<String> results = new ArrayList<>();
    for (String word : words) {
        Map<Character, Character> map = new HashMap<>();
        int i;
        for (i = 0; i < pattern.length(); i++) {
            if (map.containsKey(pattern.charAt(i))) {
                //确保word中不会有两个字母映射到pattern中的一个字母
                if (map.get(pattern.charAt(i)) != word.charAt(i)) {
                    break;
                }
            } else {
                //确保pattern中不会有两个字母映射到word中的一个字母
                if (map.containsValue(word.charAt(i))) {
                    break;
                }
                map.put(pattern.charAt(i), word.charAt(i));
            }
        }
        if (i == pattern.length()) {
            results.add(word);
        }
    }
    return results;
}
```
