### 解题思路
end -> start通过BFS
start -> end通过DFS

### 代码

```java
class Solution {
    public List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        List<List<String>> results = new ArrayList<>();

        //将wordList转成字典，查询O(1)时间复杂度
        Set<String> dict = new HashSet<>();
        for (String s : wordList) {
            dict.add(s);
        }
        if(!dict.contains(endWord)){
            return new ArrayList<>();
        }
        
        dict.add(beginWord);
        dict.add(endWord);

        Map<String, Integer> distince = new HashMap<>();
        bfs(endWord, beginWord, dict, distince);

        dfs(results, new ArrayList<>(), beginWord, endWord, dict, distince);

        return results;
    }

    private void dfs(List<List<String>> results, List<String> subsets, String crt, String endWord, Set<String> dict, Map<String, Integer> distince) {
        subsets.add(crt);
        if(crt.equals(endWord)) {
            results.add(new ArrayList<>(subsets));
        }

        for (String next : getNextWord(crt, dict)) {
            if(distince.get(crt) == distince.get(next) + 1) {
                dfs(results, subsets, next, endWord, dict, distince);
            }
        }
        subsets.remove(subsets.size() - 1);
    }
    
    private void bfs(String beginWord, String endWord, Set<String> dict, Map<String, Integer> distince) {
        Queue<String> queue = new LinkedList<>();
        queue.add(beginWord);
        distince.put(beginWord, 0);

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                for (String next : getNextWord(word, dict)) {
                    if (distince.containsKey(next)) {
                        continue;
                    }

                    distince.put(next, distince.get(word) + 1);
                    queue.add(next);
                }
            }
        }
    }

    private List<String> getNextWord(String word, Set<String> dict) {
        List<String> list = new ArrayList<>();
        char[] chars = word.toCharArray();
        char[] chars2 = word.toCharArray();

        for (int i = 0; i < word.length(); i++) {
            for (char w = 'a'; w <= 'z'; w++) {
                if (chars[i] == w) {
                    continue;
                }

                chars2[i] = w;
                String str = new String(chars2);
                if (dict.contains(str)) {
                    list.add(str);
                }
                chars2[i] = chars[i];
            }
        }

        return list;
    }
}
```