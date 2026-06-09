### 解题思路
分组聚合+优先队列

### 代码

```java
class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); ++i) {
            map.put(s.charAt(i), map.getOrDefault(s.charAt(i),0) + 1);                        
        }

        PriorityQueue<Latter> queue = new PriorityQueue<>();

        for (Map.Entry<Character, Integer> entry: map.entrySet()) {
            queue.add(new Latter(entry.getKey(), entry.getValue()));
        }

        StringBuilder result = new StringBuilder();

        while (!queue.isEmpty()){
            Latter latter = queue.poll();
            for (int i =0; i<latter.frequency;i++)
                result.append(latter.latter);
        }

        return result.toString();
    }

    public class Latter implements Comparable<Latter>{
        public Character latter;
        public int frequency;

        public Latter(Character latter, int frequency) {
            this.latter = latter;
            this.frequency = frequency;
        }

        @Override
        public int compareTo(Latter o) {
            return o.frequency - this.frequency;
        }
    }
}
```