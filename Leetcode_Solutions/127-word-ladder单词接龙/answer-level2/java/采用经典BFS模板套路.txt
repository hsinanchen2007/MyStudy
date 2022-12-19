# **1.思路**
方法1：无向图BFS，可套用经典BFS模板。
方法2：众多题解里提到的双端BFS。

方法2比较好，但面试时不一定立马能想到，鉴于众多题解里已经有该解法的详细代码，在此不再写代码。翻看众多题解发现，经典BFS解法写的不一而足，在此重点梳理一下经典BFS模板，以及对应代码。

# **2.经典BFS模板**
```
void BFS()
{
    1.判断边界条件，是否能直接返回结果的。

    2.定义队列。
    
    3.定义备忘录。

    4.将起始位置加入到队列中，同时更新备忘录。


    5.BFS遍历
    while (队列不为空) {
        5.1 获取当前队列中的元素个数。
        for (元素个数) {
            5.2 取出一个位置节点。
            
            5.3 判断是否到达终点位置。
            
            5.4 获取它对应的下一个所有的节点。
            
            5.5 条件判断，过滤掉不符合条件的位置。
            
            5.6 新位置重新加入队列，并更新备忘录。
        }
    }
}
```

方法1（经典BFS）代码：
```
class Solution {
    public int ladderLength(String beginWord, String endWord, List<String> wordList) {
        if (!wordList.contains(endWord)) {
            return 0;
        }

        int len = beginWord.length();
        // 将字符替换模板“a*b”作为key，所有符合模板的字符串作为value创建哈希表，以此为边建立无向图
        Map<String, List<String>> patternMap = generatePatternMap(wordList, len);

        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();

        queue.add(beginWord);
        visited.add(beginWord);

        int res = 1;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();

                if (word.equals(endWord)) {
                    return res;
                }

                for (int j = 0; j < len; j++) {
                    String pattern = word.substring(0, j) + "*" + word.substring(j + 1, len);
                    List<String> nextWords = patternMap.getOrDefault(pattern, new ArrayList<>());
                    for (String nextWord : nextWords) {
                        if (!visited.contains(nextWord)) {
                            queue.add(nextWord);
                            visited.add(nextWord);
                        }
                    }
                }
            }
            res++;
        }
        return 0;
    }


    public Map<String, List<String>> generatePatternMap(List<String> wordList, int len) {
        Map<String, List<String>> map = new HashMap<>();
        for (String word : wordList) {
            for (int i = 0; i < len; i++) {
                String pattern = word.substring(0, i) + "*" + word.substring(i + 1, len);
                map.putIfAbsent(pattern, new ArrayList<>());
                map.get(pattern).add(word);
            }
        }
        return map;
    }
}
```
