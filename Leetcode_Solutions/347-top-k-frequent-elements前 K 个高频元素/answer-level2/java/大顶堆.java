### 代码

```java
class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {

        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; ++i) {
            map.put(nums[i], map.getOrDefault(nums[i],0) + 1);                        
        }

        PriorityQueue<Number> queue = new PriorityQueue<>();

        for (Map.Entry<Integer, Integer> entry: map.entrySet()) {
            queue.add(new Number(entry.getKey(), entry.getValue()));
        }

        List<Integer> list = new ArrayList<>(); 
        while (k-- > 0 && !queue.isEmpty()){
            Number number = queue.poll();
            list.add(number.number);
        }
        return list;
    }

     public class Number implements Comparable<Number>{
        public int number;
        public int frequency;

        public Number(int number, int frequency) {
            this.number = number;
            this.frequency = frequency;
        }

        @Override
        public int compareTo(Number o) {
            return o.frequency - this.frequency;
        }
    }
}
```