### 解题思路
BFS

### 代码

```java
class Solution {
    public int minMutation(String start, String end, String[] bank) {
        Set<String> dict = new HashSet<>();
        for (String s : bank) {
            dict.add(s);
        }

        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add(start);
        visited.add(start);

        int distance = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                for (String s : getNextWords(word, dict)) {
                    if(visited.contains(s)){
                        continue;
                    }
                    if(end.equals(s)){
                        return distance + 1;
                    }

                    queue.add(s);
                    visited.add(s);
                }
            }

            distance++;
        }
        return -1;
    }

    private List<String> getNextWords(String word, Set<String> dict) {
        List<String> list = new ArrayList<>();
        char[] change = new char[]{'A', 'C', 'G', 'T'};

        char[] chars = word.toCharArray();
        char[] chars2 = word.toCharArray();

        for (int i = 0; i < chars.length; i++) {
            for (int j = 0; j < 4; j++) {
                if(chars[i] == change[j]){
                    continue;
                }

                chars2[i] = change[j];
                String nextWord = new String(chars2);
                if(dict.contains(nextWord)){
                    list.add(nextWord);
                }
                chars2[i] = chars[i];
            }
        }

        return list;
    }
}
```