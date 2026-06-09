### 解析
其实这是非常经典的统计前K个高频元素的题目，只要我们合理的运用数据结构，这个题目是非常简单的。

首先我们肯定要统计数字中每个元素出现的次数，这是毫无疑问的。所以我们可以使用一个Map的数据结构，key是数组中的每个元素，value是这个元素出现的次数。完整这个步骤我们需要遍历一遍数组，它的时间复杂度是O(logN)。

然后我们需要在这个Map中统计前K个高频元素。其实你自要想到优先队列这个数据结构的呢，就非常简单了。我们创建一个容量为k的优先队列，然后遍历上面的Map，将每个元素的出现次数放到这个优先队列。
等到我们遍历完这个map后，这个优先队列存放的就是前K个高频元素。这个过程中，遍历Map的时间复杂度是O(N)，每次向优先队列中插入元素的时间复杂度是O(logK)，合起来的时间复杂度是O(N * logK)

### Java实现
```java
import java.util.*;

class Solution {
    /**
     * 我们在向最小堆中插入值的时候，需要用一个对象来：
     *   - 包装元素本身以及它出现的频率
     *   - 并实现compareTo接口
     */
    private class Freq implements Comparable<Freq>{
        private int ele;
        private int freq;

        private Freq(int ele, int freq) {
            this.ele = ele;
            this.freq = freq;
        }

        /**
         * 频率高的优先级更加的高
         */
        @Override
        public int compareTo(Freq anther) {
            if (this.freq > anther.freq){
                return 1;
            } else if (this.freq < anther.freq){
                return -1;
            } else {
                return 0;
            }
        }
    }
    public List<Integer> topKFrequent(int[] nums, int k) {
        // key是数组中的每个元素，value是这个元素出现的频率
        Map<Integer, Integer> eleToFrequency = new HashMap<>();

        // 遍历数组，统计频率，时间复杂度是 O(N)
        for (int num : nums){
            if (!eleToFrequency.containsKey(num)){
                eleToFrequency.put(num, 1);
            } else {
                eleToFrequency.put(num, eleToFrequency.get(num) + 1);
            }
        }

        // Java自带的最小堆
        PriorityQueue<Freq> pq = new PriorityQueue<>();

        // 遍历上面的Map，将每个元素的出现次数放到这个优先队列中
        for(Integer key : eleToFrequency.keySet()){
            pq.add(new Freq(key, eleToFrequency.get(key)));

            // 如果队列超过了k，就可以删除当前频率最小元素了的了
            if (pq.size() == k + 1){
                pq.remove();
            }
        }
        
        // 将得到的优先队列转化为list
        LinkedList<Integer> list = new LinkedList<>();
        for (Freq ele : pq){
            list.addFirst(ele.ele);
        }
        return list;
    }
}
```

### 总结
要点就是Map和优先队列这两种数据结构

https://github.com/fish-stack/AlgoMath/issues/8
