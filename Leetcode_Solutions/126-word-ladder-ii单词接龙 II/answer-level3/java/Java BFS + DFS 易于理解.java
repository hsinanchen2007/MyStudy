### 解法一： DFS + BFS

#### 分析：
- 首先，我们利用`wordList`中给出的单词（注意到`beginword`可能不在`wordList`中，我们需要把`beginWord`也加进图中），构建一张无向图，图中节点是每一个`word`，两个节点连接的条件是其中一个单词可以通过只改变一个字母从而转换成另一个单词。
- 利用`BFS`我们来计算从`beginWord`转化到`endWord`的最短长度`minDist`。
- 利用`DFS`，我们把每一个长度为`minDist`的从`beginWord`转化到`endWord`的序列加入答案集合中，并返回。
- **注意：** 这样的解法会超时，因为我们在`DFS`利用这个`minDist`来做简单的剪枝操作，但是在一些情况下（`endWord`深度足够大），`DFS`时间复杂度仍然很高。我们需要`DFS`时过滤掉一些节点来提高搜索效率。
- **优化：** 注意到在做BFS时，我们可以记录下每一层搜索过的`word`的集合，那么在做`DFS`的每一次搜索时，我们选择的是与**当前节点相连接的节点的集合**与之前**BFS记录下该层搜索过的word的集合**的**交集**，以过滤掉很多不需要搜索的节点。

#### 复杂度分析：
- 时间复杂度：$O(N^2)$ 其中$N$为`wordList`的长度
- 空间复杂度：$O(N)$


#### 实现：

- 利用一个`Map<String, Set<String>> map`存放生成的无向图。
- 利用一个`Map<Integer, Set<String>> nxtMap` 来存放`BFS`时，每一层上搜索过的节点
```java []
class Solution {
    private Map<String, Set<String>> map;      // 存储构建好的无向图
    private Map<Integer, Set<String>> nxtMap;  // 记录每个搜索层次上的candidate节点
    private List<List<String>> ans;            // 存储答案
    private int minDist;                       // 转化序列的最短长度
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        wordList.add(beginWord);
        this.map = new HashMap<>();
        this.nxtMap = new HashMap<>();
        this.ans = new ArrayList<>();
        int n = wordList.size();

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                String a = wordList.get(i), b = wordList.get(j);
                if (check(a, b)) {
                    map.putIfAbsent(a, new HashSet<>());
                    map.putIfAbsent(b, new HashSet<>());
                    map.get(a).add(b);
                    map.get(b).add(a);
                }
            }
        }

        minDist = BFS(beginWord, endWord);
        // 如果minDist为-1，说明不存在这样的转化序列，直接返回空集
        if (minDist == -1) return ans;
        DFS(beginWord, endWord, new HashSet<String>(), new ArrayList<String>());
        return ans;
        
    }

    private void DFS(String cur, String end, Set<String> visit, List<String> path) {
        visit.add(cur);
        path.add(cur);
        if (path.size() == minDist) {
            if (cur.compareTo(end)==0) {
                ans.add(new ArrayList<>(path));
            }
        } else {
            for (String nxt : map.get(cur)) {
                // 优化： 取当前未访问过，且在该层次候选集合中的节点
                if (visit.contains(nxt) || !nxtMap.get(path.size()).contains(nxt)) continue;
                DFS(nxt, end, visit, path);
            }
        }
        visit.remove(cur);
        path.remove(path.size()-1);
       
    }

    private int BFS(String beginWord, String endWord) {
        int level = 0;
        Set<String> visit = new HashSet<>();
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        visit.add(beginWord);

        while (!queue.isEmpty()) {
            int size = queue.size();
            nxtMap.put(level+1, new HashSet<>());
            for (int i = 0; i < size; i++) {
                String cur = queue.poll();
                if (cur.compareTo(endWord)==0) return level+1;
                for (String nxt : map.getOrDefault(cur, new HashSet<>())) {
                    if (visit.contains(nxt)) continue;
                    visit.add(nxt);
                    queue.offer(nxt);
                    nxtMap.get(level+1).add(nxt);
                }
            }
            level++;
        }
        return -1;
    }

    // 判断字符串a能否通过只改变一个字母转化为b
    private boolean check(String a, String b) {
        int cnt = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) cnt++;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }
}
```

