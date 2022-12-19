- 总体思路
    - 先双向广度优先bfs，确定在相遇时，所有涉及的相邻词映射 ```neighborsMap: Map<String, List<String>>``` ，如 ```a, [b, c]``` , ```b, [d, f]``` , ```c, [f]```
    - 再基于 ```neighborsMap``` 做深度优先dfs，确定每一条路径 ```path``` ，其中 ```path``` 还利用 ```Deque``` 配合dfs拼路径
- **不是我的解法**，借鉴的是提交中最快的代码模板——感谢无名老铁！*我只是理解代码的搬运工*
- 为了方便理解，调整了参数、方法命名，精简了冗余代码，添加了必要注释
```java
public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
    // base condition
    Set<String> meets = new HashSet<>(wordList);
    if (!meets.contains(endWord)) return Collections.emptyList();

    Set<String> begin = new HashSet<>(Collections.singleton(beginWord));
    Set<String> end = new HashSet<>(Collections.singleton(endWord));

    // 相邻词映射
    Map<String, List<String>> neighborsMap = new HashMap<>();
    if (!doubleBfs(begin, end, neighborsMap, true, meets)) return Collections.emptyList(); // not find

    List<List<String>> result = new ArrayList<>();
    dfs(neighborsMap, result, beginWord, endWord, new LinkedList<>());
    return result;
}

// 双向广度优先，并确定在相遇时（找到最短路径时）所涉及的相邻词集合 neighbors
private boolean doubleBfs(Set<String> begin, Set<String> end, Map<String, List<String>> neighborsMap,
                            boolean isFromBeginToEnd, Set<String> meets) {
    // terminator
    if (begin.size() == 0) return false;

    // process
    meets.removeAll(begin);

    // 在当前层是否已相遇
    boolean isMeetInCurrLevel = false;

    Set<String> nextLevels = new HashSet<>();
    // every word
    for (String beginWord : begin) {
        char[] arr = beginWord.toCharArray();
        // every letter
        for (int j = 0; j < arr.length; j++) {
            char swap = arr[j];
            // every other letter
            for (char i = 'a'; i <= 'z'; i++) {
                arr[j] = i;
                String newWord = String.valueOf(arr);
                if (!meets.contains(newWord)) continue;

                nextLevels.add(newWord);

                // 记录相邻词映射
                String key = isFromBeginToEnd ? beginWord : newWord;
                String neighbor = isFromBeginToEnd ? newWord : beginWord;
                if (!neighborsMap.containsKey(key)) neighborsMap.put(key, new ArrayList<>());
                neighborsMap.get(key).add(neighbor);

                // 而不是立刻返回，还要在这一层多找找
                if (end.contains(newWord)) isMeetInCurrLevel = true;
            }
            arr[j] = swap;
        }
    }

    if (isMeetInCurrLevel) return true;

    // drill down
    // 少的找多的
    if (nextLevels.size() > end.size()) return doubleBfs(end, nextLevels, neighborsMap, !isFromBeginToEnd, meets);
    else return doubleBfs(nextLevels, end, neighborsMap, isFromBeginToEnd, meets);
}

// 深度优先，确定路径
private void dfs(Map<String, List<String>> neighborsMap, List<List<String>> result,
                    String begin, String end, Deque<String> path) {
    // terminator: complete appending result, but path back to empty
    if (result.size() > 0 && path.size() == 0) return;

    // process
    path.addLast(begin); // add last 添加到路径末尾

    // 完成一条路径
    if (begin.equals(end)) {
        result.add(new ArrayList<>(path)); // 避免引用问题
    } else if (neighborsMap.containsKey(begin)) { // 有相邻词
        // drill down
        // 遍历相邻词并递归
        for (String neighbor : neighborsMap.get(begin)) {
            dfs(neighborsMap, result, neighbor, end, path);
        }
    }

    // back tracking
    path.removeLast(); // 退一步，以便找另一条路径
}
```