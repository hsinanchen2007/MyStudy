```
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Map<String, List<String>> graph = new HashMap<>(); // 保存图
        construct(beginWord, wordList, graph); // 构造图
        List<Integer> endPos = new ArrayList<>(); // 保存endWord节点的索引
        List<QItem> queue = new ArrayList<>(); // 节点队列
        bfs(beginWord, endWord, graph, queue, endPos);
        List<List<String>> ret = new ArrayList<>();
        // System.out.println(queue);
        for (int i = 0; i < endPos.size(); i++) {
            List<String> path = new ArrayList<>();
            int pos = endPos.get(i);
            while (pos != -1) {
                QItem item = queue.get(pos);
                path.add(item.word);
                pos = item.pre;
            }
            List<String> newPath = new ArrayList<>();
            for (int j = path.size() - 1; j >= 0; j--) {
                newPath.add(path.get(j));
            }
            ret.add(newPath);
        }
        return ret;
    }

    void bfs(String beginWord, String endWord, Map<String, List<String>> graph, List<QItem> queue, List<Integer> endPos) {
        Map<String, Integer> visit = new HashMap<>(); // 记录到达节点的步数
        int minStep = 0; // 记录到达endWord的最小步数
        queue.add(new QItem(beginWord, -1, 1));
        visit.put(beginWord, 1); // 使用List保存路径节点，不删除队头
        int front = 0; // 记录队列头指针
        while (front < queue.size()) {
            QItem top = queue.get(front);
            if (minStep != 0 && top.step > minStep) { // 表示所有最短路径都搜索完了
                break;
            }
            if (top.word.equals(endWord)) {
                minStep = top.step;
                endPos.add(front);
            }
            List<String> table = graph.get(top.word); // 当前节点的邻接表
            for (int i = 0; i < table.size(); i++) {
                if (!visit.containsKey(table.get(i)) || visit.get(table.get(i)) == top.step + 1) { // 什么时候入队！以及另一条路径
                    queue.add(new QItem(table.get(i), front, top.step + 1));
                    visit.put(table.get(i), top.step + 1);
                }
            }
            front++; // 遍历完该节点的邻接表后，头指针向后移一位
        }
    }

    // 使用map构造图，邻接表
    public void construct(String beginWord, List<String> wordList, Map<String, List<String>> graph) {
        boolean hasBeginWord = false; // 因为队列不删除，队列中可能包含beginWord，不能包含多个beginWord
        for (int i = 0; i < wordList.size(); i++) {
            if (wordList.get(i).equals(beginWord)) {
                hasBeginWord = true;
            }
            graph.put(wordList.get(i), new ArrayList<>());
        }
        if (!hasBeginWord) {
            graph.put(beginWord, new ArrayList<>());
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
            if (!hasBeginWord && connect(beginWord, wordList.get(i))) {
                graph.get(beginWord).add(wordList.get(i));
            }
        }

        // for (String key : graph.keySet()) {
        //     System.out.println(key + ": " + graph.get(key));
        // }
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

    // 队列元素
    static class QItem {
        String word;
        int pre; // 到达该点的父节点
        int step; // 到达该点的步数
        QItem(String word, int pre, int step) {
            this.word = word;
            this.pre = pre;
            this.step = step;
        }

        public String toString() {
            return word + ", " + pre + ", " + step;
        }
    }
}
```
