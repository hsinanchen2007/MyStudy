思路：
1. 找出所有near距离为1的字母:  题目要求每次只能转换一个字母。
   Map<String,Set<String>> map   key: 该字母。 Set<String> 与该字母距离为1的全局。

2.  如果该map里不存在endword 或者endWord 和 beginWord的相近的字符个数为0，返回0.

3. 创建一个Map<String,Integer> distance ，来表示每一个字母距离endWord的最短距离。

4. 从key=endWord，还是遍历1所构建的map。直到计算出distance里包含beginWord。或者 找不出下一个更近的单词。终止。


```java

public class Lesson127 {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (wordList == null || wordList.size() == 0) {
            return 0;
        }
        Map<String, Set<String>> near = new HashMap<>();
        wordList.add(beginWord);
        for (int i = 0; i < wordList.size(); i++) {
            String word = wordList.get(i);
            Set<String> sets = near.getOrDefault(word, new HashSet<>());
            for (int j = i + 1; j < wordList.size(); j++) {
                if (word.equals(wordList.get(j))) {
                    continue;
                }

                if (isNear(word, wordList.get(j))) {
                    String wordNear = wordList.get(j);
                    sets.add(wordNear);
                    if (!near.containsKey(wordNear)) {
                        near.put(wordNear, new HashSet<>());
                    }
                    near.get(wordNear).add(word);
                }
            }
            near.put(word, sets);
        }

        if (!near.containsKey(endWord) || near.get(beginWord).isEmpty() || near.get(endWord).isEmpty()) {
            return 0;
        }

        Map<String, Integer> distance = new HashMap<>();
        distance.put(endWord, 1);
        Queue<String> queue = new ArrayDeque<>();
        queue.add(endWord);
        while (!queue.isEmpty() && !distance.containsKey(beginWord)) {
            String s = queue.poll();
            int addDistance = distance.getOrDefault(s, 0) + 1;
            for (String word : near.get(s)) {
                if (distance.containsKey(word)) {
                    continue;
                }

                queue.add(word);
                if (near.get(word).isEmpty()) {
                    continue;
                }
                distance.put(word, addDistance);
            }
        }
        return distance.getOrDefault(beginWord, 0);
    }

    private boolean isNear(String s1, String s2) {
        int diff = 0;
        for (int i = 0; i < s1.length() && diff <= 1; i++) {
            if (s1.charAt(i) != s2.charAt(i)) {
                diff++;
            }
        }

        return diff <= 1;
    }

}

class WordDistance {
    String word;
    String near;
}
```


