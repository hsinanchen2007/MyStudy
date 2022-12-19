### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for (String word : words) {
           if(!map.containsKey(word)) {
               map.put(word, 1);
           } else {
               map.put(word, map.get(word) + 1);
           }
        }

        Comparator<WordFrequent> comparator = (o1, o2) -> {
            if (o1.frequent != o2.frequent) {
                return o1.frequent - o2.frequent;
            }

            return o2.word.compareTo(o1.word);
        };

        Queue<WordFrequent> queue = new PriorityQueue<>(comparator);

        for (String word : map.keySet()) {
            if(queue.size() < k) {
                queue.add(new WordFrequent(word, map.get(word)));
            } else {
                if(comparator.compare(new WordFrequent(word, map.get(word)), queue.peek()) > 0) {
                    queue.poll();
                    queue.add(new WordFrequent(word, map.get(word)));
                }
            }
        }

        List<String> res = new ArrayList<>();
        while(!queue.isEmpty()) {
            res.add(0, queue.poll().word);
        }

        return res;
    }
}


class WordFrequent {
    String word;
    Integer frequent;

    public WordFrequent(String word, Integer frequent) {
        this.word = word;
        this.frequent = frequent;
    }
}
```