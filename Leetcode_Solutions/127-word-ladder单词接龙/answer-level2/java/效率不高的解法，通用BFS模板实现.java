```
public class Solution {
    /**
     * 127. 单词接龙
     * https://leetcode-cn.com/problems/word-ladder/
     *
     * @param beginWord 开始单词
     * @param endWord 结尾单词
     * @param wordList 字典
     * @return 最短转换序列
     */
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }

        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        Set<String> set = new HashSet<>();
        int ans = 0;
        while (!queue.isEmpty()) {
            int count = queue.size();
            ans++;
            for (int i = 0; i < count; i++) {
                String curr = queue.poll();
                if (endWord.equals(curr)) {
                    return ans;
                }

                if (!set.contains(curr)) {
                    set.add(curr);
                    for (String word : wordList) {
                        if (isValid(word, curr)) {
                            queue.offer(word);
                        }
                    }
                }
            }
        }

        return 0;
    }

    private boolean isValid(String source, String target) {
        int count = 0;
        for (int i = 0; i < target.length(); i++) {
            if (source.charAt(i) != target.charAt(i)) {
                count++;
            }
        }

        return count == 1;
    }
}
```
