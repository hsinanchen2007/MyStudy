开始对题目理解错误，用了单个单词去构建图，看了 [@zxy0917](/u/zxy0917/) 的题解才明白，按照自己的思路实现如下：
通过一次遍历记录 入度 和 边
```
class Solution {
    public String alienOrder(String[] words) {
        // 存放结果 最后转成String
        List<Character> result = new ArrayList<Character>();
        // 入度
        Map<Character, Integer> indegree = new HashMap<>();
        // 存放边
        Map<Character, Set<Character>> edges = new HashMap<>();
        // 判断是否处理过
        Map<Character, Character> visited = new HashMap<>();
        for (int i = 0; i < words.length - 1; i++) {
            String word = words[i];
            // 注意：只保存第一个不同的字符顺序
            for (int j = 0; j < word.length() && j < words[i + 1].length(); j++) {
                // 两个字符相等 continue
                if (word.charAt(j) == words[i + 1].charAt(j)) {
                    continue;
                }
                // 是否计算过
                if (visited.containsKey(word.charAt(j)) && visited.get(word.charAt(j)) == words[i + 1].charAt(j)) {
                    break;
                }
                // "wr" => w->r ==== r 的 indegree +1
                // w 的 edges 增加 r
                indegree.put(words[i + 1].charAt(j), indegree.getOrDefault(words[i + 1].charAt(j), 0) + 1);
                Set<Character> set = edges.getOrDefault(word.charAt(j), new HashSet<>());
                set.add(words[i + 1].charAt(j));
                edges.put(word.charAt(j), set);

                visited.put(word.charAt(j), words[i + 1].charAt(j));
                break;
            }
        }

        Queue<Character> queue = new LinkedList<>();
        Set<Character> joined = new HashSet<>();
        int count = 0;
        Set<Character> set = new HashSet<>();
        // 把入度为0的点加入
        for (int i = 0; i < words.length; i++) {
            String word = words[i];
            for (int j = 0; j < word.length(); j++) {
                if (!indegree.containsKey(word.charAt(j)) && !joined.contains(word.charAt(j))) {
                    queue.add(word.charAt(j));
                    joined.add(word.charAt(j));
                }
                if (!set.contains(word.charAt(j))) {
                    count++;
                    set.add(word.charAt(j));
                }
            }
        }

        // bfs
        while (!queue.isEmpty()) {
            Character c = queue.poll();
            result.add(c);
            if (edges.containsKey(c)) {
                for (Character character : edges.get(c)) {
                    indegree.put(character, indegree.get(character) - 1);
                    if (indegree.get(character) == 0) {
                        queue.add(character);
                    }
                }
            } 
        }

        StringBuilder sb = new StringBuilder();
        for (Character ch : result) {
            sb.append(ch);
        }
        // 是否有拓扑序 没有返回 ""
        if (sb.length() != count) {
            return "";
        }

        return sb.toString();
    }
}
```
