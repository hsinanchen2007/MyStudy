### 解题思路
BFS，和单词接龙那道题一样。

### 代码

```java
class Solution {
    public int openLock(String[] deadends, String target) {
        if(target.equals("0000")){
            return 0;
        }

        Set<String> dict = new HashSet<>();
        for (String deadend : deadends) {
            dict.add(deadend);
        }
        if(dict.contains("0000")){
            return -1;
        }

        Queue<String> queue = new LinkedList<>();
        Set<String> visited = new HashSet<>();
        queue.add("0000");
        visited.add("0000");
        int distance = 0;

        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                String word = queue.poll();
                for (String s : getNextWord(word, dict)) {
                    if(visited.contains(s)){
                        continue;
                    }
                    if(s.equals(target)){
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

    private List<String> getNextWord(String word, Set<String> dict) {
        char[] chars = word.toCharArray();
        char[] chars2 = word.toCharArray();

        List<String> list = new ArrayList<>();

        for (int i = 0; i < chars.length; i++) {
            chars2[i] = Character.forDigit((chars2[i] - '0' + 1) % 10, 10);
            String nextWord = new String(chars2);
            if(!dict.contains(nextWord)){
                list.add(nextWord);
            }

            chars2[i] = chars[i];

            chars2[i] = Character.forDigit((chars2[i] - '0' + 9) % 10, 10);
            nextWord = new String(chars2);
            if(!dict.contains(nextWord)){
                list.add(nextWord);
            }

            chars2[i] = chars[i];
        }
        return list;
    }
}
```