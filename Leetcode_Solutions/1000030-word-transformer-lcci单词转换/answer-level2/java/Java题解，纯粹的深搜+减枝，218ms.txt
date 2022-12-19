1. 已经找到的单词后面不需要再经过了，故需要个hashSet.remove(nextWord)。
2. 仔细审题发现只要给出一个答案即可，故加了个剪枝条件(result == null)。


```
class Solution {
    private Set<String> hashSet = new HashSet<>();

    private Map<Integer, Set<Character>> wordReplaceList = new HashMap<>();

    private String result;

    public List<String> findLadders(String beginWord, String endWord, List<String> wordList) {
        for (String word : wordList) {
            hashSet.add(word);
            for (int i = 0; i < word.length(); i++) {
                Set<Character> set = wordReplaceList.computeIfAbsent(i, k -> new HashSet<>());
                set.add(word.charAt(i));
            }
        }
        if (!hashSet.contains(endWord)) {
            return new ArrayList<>();
        }

        hashSet.remove(beginWord);
        dfs(beginWord, beginWord, endWord);
        return result == null ? new ArrayList<>() : Arrays.stream(result.split(",")).collect(Collectors.toList());
    }

    private void dfs(String word, String prefix, String endWord) {
        if (word.equals(endWord)) {
            result = prefix;
            return;
        }
        for (int i = 0; i < word.length(); i++) {
            for (Character ch : wordReplaceList.get(i)) {
                if (ch == word.charAt(i)) {
                    continue;
                }
                String nextWord = word.substring(0, i) + ch + word.substring(i + 1);
                if (!hashSet.contains(nextWord)) {
                    continue;
                }
                hashSet.remove(nextWord);
                if (result == null) {
                    dfs(nextWord, prefix + "," + nextWord, endWord);
                }
            }
        }
    }
}
```
