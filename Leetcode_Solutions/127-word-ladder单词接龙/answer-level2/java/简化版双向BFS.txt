不通过傻枚举字符串去匹配字符串是否在列表中，而是通过先预处理wordList，然后通过 * 去匹配符合规则的字符串列表。

```
class Solution {
    private int length;
    private Map<String, List<String>> dict;

    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }
        this.dict = new HashMap<>();
        this.length = beginWord.length();
        wordList.forEach(
                item -> {
                    for (int i = 0; i < length; i++) {
                        String newWord = item.substring(0, i) + "*" + item.substring(i + 1, length);
                        List<String> words = dict.computeIfAbsent(newWord, value ->
                                new ArrayList<>());
                        words.add(item);
                        dict.put(newWord, words);
                    }
                }
        );
        Set<String> startSet = new HashSet<>();
        Set<String> endSet = new HashSet<>();
        Set<String> visited = new HashSet<>();
        startSet.add(beginWord);
        endSet.add(endWord);
        int level = 1;
        while (!startSet.isEmpty() && !endSet.isEmpty()) {
            if (endSet.size() < startSet.size()) {
                Set<String> temp = startSet;
                startSet = endSet;
                endSet = temp;
            }
            Set<String> temp = new HashSet<>();
            for (String word : startSet) {
                char[] chars = word.toCharArray();
                for (int i = 0; i < chars.length; i++) {
                    char oldChar = chars[i];
                    chars[i] = '*';
                    String likeWord = String.valueOf(chars);
                    List<String> likeWordList = dict.get(likeWord);
                    if (likeWordList == null) {
                        chars[i] = oldChar;
                        continue;
                    }
                    for (String target : likeWordList) {
                        if (endSet.contains(target)) {
                            return level + 1;
                        }
                        if (!visited.contains(target)) {
                            visited.add(target);
                            temp.add(target);
                        }
                    }
                    chars[i] = oldChar;
                }
            }
            startSet = temp;
            level++;
        }
        return 0;
    }
}
```
