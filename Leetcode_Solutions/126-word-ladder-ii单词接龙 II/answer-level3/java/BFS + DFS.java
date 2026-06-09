## 思路:

这道题 `BFS + DFS`

用`BFS`求从`beginWord` 到`endWord`最短距离,经过哪些单词, 用字典记录离`beginWord`的距离;

用`DFS`求从`beginWord` 到`endWord`有哪些路径

`Java` 代码写的我怀疑人生, 可以帮我简化吗?

## 代码:

```python [1]
class Solution:
    def findLadders(self, beginWord: str, endWord: str, wordList: List[str]) -> List[List[str]]:
        from collections import defaultdict
        wordList = set(wordList)
        res = []
    	# 记录单词下一步能转到的单词
        next_word_dict = defaultdict(list)
        # 记录到beginWord距离
        distance = {}
        distance[beginWord] = 0
		
        # 找一个单词能转到的单词
        def next_word(word):
            ans = []
            for i in range(len(word)):
                for j in range(97, 123):
                    tmp = word[:i] + chr(j) + word[i + 1:]
                    if tmp != word and tmp in wordList:
                        ans.append(tmp)
            return ans
		# 求到beginWord的距离
        def bfs():
            cur = [beginWord]
            step = 0
            flag = False
            while cur:
                step += 1
                next_time = []
                for word in cur:
                    for nw in next_word(word):
                        next_word_dict[word].append(nw)
                        if nw == endWord:
                            flag = True
                        if nw not in distance:
                            distance[nw] = step
                            next_time.append(nw)
                if flag:
                    break
                cur = next_time
		# 遍历所有从beginWord到endWord的路径
        def dfs(tmp, step):
            if tmp[-1] == endWord:
                res.append(tmp)
                return
            for word in next_word_dict[tmp[-1]]:
                if distance[word] == step + 1:
                    dfs(tmp + [word], step + 1)

        bfs()
        dfs([beginWord], 0)
        return res
```



```java [1]
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        Set<String> wordList_set = new HashSet<>(wordList);
        List<List<String>> res = new ArrayList<>();
        Map<String, ArrayList<String>> next_word_map = new HashMap<>();
        Map<String, Integer> distance = new HashMap<>();

        bfs(beginWord, endWord, next_word_map, distance, wordList_set);
        dfs(beginWord, endWord, next_word_map, 0, res, new ArrayList<String>(Arrays.asList(beginWord)), distance);
        return res;
    }

    private void dfs(String beginWord, String endWord, Map<String, ArrayList<String>> next_word_map, int step, List<List<String>> res, ArrayList<String> tmp, Map<String, Integer> distance) {
        
        if (tmp.get(tmp.size() - 1).equals(endWord)) res.add(new ArrayList<>(tmp));
        for (String word : next_word_map.get(tmp.get(tmp.size() - 1))) {
            tmp.add(word);
            if (distance.get(word) == step + 1) dfs(word, endWord, next_word_map, step + 1, res, tmp, distance);
            tmp.remove(tmp.size() - 1);
        }
    }

    private void bfs(String beginWord, String endWord, Map<String, ArrayList<String>> next_word_map, Map<String, Integer> distance, Set<String> wordList_set) {
        for (String s : wordList_set) next_word_map.put(s, new ArrayList<String>());
        next_word_map.put(beginWord, new ArrayList<>());
        Queue<String> queue = new LinkedList<>();
        queue.offer(beginWord);
        distance.put(beginWord, 0);
        boolean flag = false;
        int step = 0;
        while (!queue.isEmpty()) {
            step++;
            int n = queue.size();
            for (int i = 0; i < n; i++) {
                String word = queue.poll();
                for (String nw : next_word(word, wordList_set)
                ) {
                    next_word_map.getOrDefault(word, new ArrayList<>()).add(nw);
                    if (nw.equals(endWord)) flag = true;
                    if (!distance.containsKey(nw)){
                        distance.put(nw, step);
                        queue.offer(nw);   
                    } 
                    
                }
            }
            if (flag) break;
        }
    }

    private ArrayList<String> next_word(String word, Set<String> wordList_set) {
        ArrayList<String> ans = new ArrayList<>();

        for (int i = 0; i < word.length(); i++) {
            char[] chars = word.toCharArray();
            for (char ch = 'a'; ch <= 'z'; ch++) {
                chars[i] = ch;
                String tmp = new String(chars);
                if (!tmp.equals(word) && wordList_set.contains(tmp)) ans.add(tmp);
            }
        }
        return ans;
    }
}
```

