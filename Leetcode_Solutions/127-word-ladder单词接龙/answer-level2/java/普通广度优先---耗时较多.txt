？进阶---双向广度（还未研究）？
```
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        Map<String, List<String>> graph = new HashMap<>();
        contractGraph(beginWord, wordList, graph); // 首先构造图，获取路径

        Set<String> visit = new HashSet<>(); // 使用set表示是否visit
        Queue<Pair> queue = new LinkedList<>();
        queue.offer(new Pair(beginWord, 1));
        visit.add(beginWord);
        while (!queue.isEmpty()) {
            Pair top = queue.poll();
            if (top.word.equals(endWord)) {
                return top.step;
            }
            List<String> item = graph.get(top.word);
            for (int i = 0; i < item.size(); i++) {
                if (!visit.contains(item.get(i))) {
                    queue.offer(new Pair(item.get(i), top.step + 1));
                    visit.add(item.get(i));
                }
            }
        }
        return 0;
    }

    // 使用map构造邻接表
    public void contractGraph(String beginWord, List<String> wordList, Map<String, List<String>> graph) {
        wordList.add(beginWord); // wordList里面可能没有beginWord
        for (int i = 0; i < wordList.size(); i++) {
            graph.put(wordList.get(i), new ArrayList<>());
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                String value1 = wordList.get(i);
                String value2 = wordList.get(j);
                if (connect(value1, value2)) {
                    graph.get(value1).add(value2);
                    graph.get(value2).add(value1);
                }
            }
        }
    }
    public boolean connect(String a, String b) {
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                count++;
            }
        }
        return count == 1;
    }

    static class Pair {
        String word;
        int step;
        Pair(String word, int step) {
            this.word = word;
            this.step = step;
        }
    }
}
```
