```java
class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Value> map = new HashMap<>(words.length);
        for (String word : words) {
            if (map.containsKey(word)) {
                map.get(word).freq++;
            } else {
                map.put(word, new Value(word, 1));
            }
        }
        PriorityQueue<Value> pq = new PriorityQueue<>(k);
        for (Value value : map.values()) {
            if (pq.size() == k) {
                if (value.compareTo(pq.peek()) > 0) {
                    pq.remove();
                    pq.offer(value);
                }
            } else {
                pq.offer(value);
            }
        }
        List<String> list = new ArrayList<>();
        while (!pq.isEmpty()) {
            list.add(pq.remove().word);
        }
        Collections.reverse(list);
        return list;
    }

    static class Value implements Comparable<Value> {
        String word;
        int freq;

        Value(String word, int freq) {
            this.word = word;
            this.freq = freq;
        }

        @Override
        public int compareTo(Value o) {
            if (freq == o.freq) {
                return o.word.compareTo(word);
            }
            return freq - o.freq;
        }

    }
}
```
