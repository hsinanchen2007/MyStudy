# 自己44ms的题解思路
- 巧妙利用 ```dict.removeAll(beginSet)``` 来避开重复访问问题 ，有的测试样例跑不过——做了调整。**最后附上外站14ms的解法**
- 关键思路: **预处理, 双端广度优先, 避免重复访问, 递归, 总是从少找向多**
- **双端广度优先**: 你来找我，我也来找你，每回合都由少的找多的 （```beginSet``` 和 ```endSet```）
- **由少的找多的**: 你来找我的下一回合有五个路口，我来找你下一回合可能有十个路口，那你来找我更快（下一递归回合之前，决定谁是 ```beginSet``` ，谁是 ```endset```）
- 不算快，贡献给有相同思路但未找到完整代码的同学们
- 再优化思考
    - 是否一定要预处理，如外站那样直接全字符逐个换26个字母来匹配是否也高效？
    - 是否可如外站 ```dict.removeAll(beginSet)``` 来避开重复访问问题—— ```dict```

```java
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) return 0; // O(n)，可先放入HashSet--O(1)
        if (beginWord.equals(endWord)) return 2;

        // 预处理 双端广度优先 避免重复访问 递归 总是从少找向多
        // 预处理
        Map<String, Set<String>> patternMap = this._getPatternMap(wordList);

        // 双端广度优先
        Set<String> beginSet = new HashSet<>(), endSet = new HashSet<>();
        beginSet.add(beginWord);
        endSet.add(endWord);

        Set<String> visited = new HashSet<>();

        // 递归
        return this._search(1, beginSet, endSet, visited, patternMap);
    }

    // BFS starts here
    private int _search(int level, Set<String> beginSet, Set<String> endSet,
                        Set<String> visited, Map<String, Set<String>> patternMap) {
        // terminator
        if (beginSet.size() == 0 || endSet.size() == 0) return 0; // 双端都找不到了

        // process
        visited.addAll(beginSet);
        level++;
        Set<String> nextLevelSet = new HashSet<>();

        // 遍历beginSet
        for (String beginWord : beginSet) {
            Set<String> neighbors = this._getNeighbors(beginWord, patternMap);
            // 遍历所有相邻词
            for (String neighbor : neighbors) {
                if (visited.contains(neighbor)) continue; // 避免重复访问
                if (endSet.contains(neighbor)) return level; // 已找到
                // 未找到，把相邻词记入下一层
                nextLevelSet.add(neighbor);
            }
            // 不能再此处 nextLevelSet.addAll(neighbors); 因为不能将 visited.contains(neighbor) 的节点放入 nextLevelSet
        }

        // drill down
        // 总是从少找向多
        if (nextLevelSet.size() <= endSet.size()) {
            beginSet = nextLevelSet;
        } else {
            beginSet = endSet;
            endSet = nextLevelSet;
        }

        return this._search(level, beginSet, endSet, visited, patternMap);

        // reverse state
    }

    // 返回给定单词表的所有匹映射，key为带*的匹配键，value为该匹配键可对应的单词集合
    private Map<String, Set<String>> _getPatternMap(List<String> wordList) {
        Map<String, Set<String>> map = new HashMap<>();
        for (String word : wordList) {
            Set<String> keys = this._getPatterns(word);
            for (String key : keys) {
                if (!map.containsKey(key)) map.put(key, new HashSet<>());
                map.get(key).add(word);
            }
        }
        return map;
    }

    // 返回给定单词的所有可能的带*匹配键
    private Set<String> _getPatterns(String word) {
        Set<String> res = new HashSet<>();
        char[] arr = word.toCharArray();
        for (int i = 0; i < arr.length; i++) {
            char temp = arr[i];
            arr[i] = '*';
            res.add(String.valueOf(arr));
            arr[i] = temp;
        }
        return res;
    }

    // 返回给定单词、在给定匹配映射中的所有可能的相邻单词
    private Set<String> _getNeighbors(String word, Map<String, Set<String>> patternMap) {
        Set<String> res = new HashSet<>();
        Set<String> patterns = this._getPatterns(word);
        for (String pattern : patterns) {
            if (!patternMap.containsKey(pattern)) continue;
            res.addAll(patternMap.get(pattern));
        }
        return res;
    }

```

# 外站14ms题解
- 为便于理解，补充了注释，优化了变量命名（如 ```dict``` 改为 ```meets```）
```java
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) return 0;
        if (beginWord.equals(endWord)) return 2;

        // 可能遇见的节点集
        Set<String> meets = new HashSet<>(wordList); // O(n)

        Set<String> beginSet = new HashSet<>(Collections.singleton(beginWord));
        Set<String> endSet = new HashSet<>(Collections.singleton(endWord));

        return this._search(1, beginSet, endSet, meets);
    }

    private int _search(int level, Set<String> beginSet, Set<String> endSet, Set<String> meets) {
        // terminator
        if (beginSet.size() == 0 || endSet.size() == 0) return 0;

        // process
        meets.removeAll(beginSet);
        level++;
        Set<String> nextLevelSet = new HashSet<>();
        // iter every begin word
        for (String beginWord : beginSet) {
            char[] chars = beginWord.toCharArray();
            // iter for every char
            for (int i = 0; i < chars.length; i++) {
                char temp = chars[i];
                // replace every letter
                for (char ch = 'a'; ch < 'z'; ch++) {
                    chars[i] = ch;
                    String newWord = String.valueOf(chars);
                    if (!meets.contains(newWord)) continue;
                    if (endSet.contains(newWord)) return level;
                    nextLevelSet.add(newWord);
                }
                // reverse
                chars[i] = temp;
            }
        }

        // drill down
        // always from less to more
        if (nextLevelSet.size() <= endSet.size()) {
            beginSet = nextLevelSet;
        } else {
            beginSet = endSet;
            endSet = nextLevelSet;
        }

        return this._search(level, beginSet, endSet, meets);
    }
```