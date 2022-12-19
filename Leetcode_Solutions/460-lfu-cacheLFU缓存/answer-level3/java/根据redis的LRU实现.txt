### 解题思路
此处撰写解题思路
每个key保存count和当前时间戳，把每个key都放进去一个pool里面，更加先count大到小，时间戳大到小排序。如果put的时候出现capacity不够，那就把pool最后一个删除
### 代码

```java
import java.util.*;
import java.time.Instant;
import java.util.concurrent.ConcurrentHashMap;
class LFUCache {

   
    private ConcurrentHashMap<Integer, Integer> element = new ConcurrentHashMap<Integer, Integer>(16);

    private int capacity;

    private int c = 0;

    private ArrayList<Node> pool = new ArrayList<Node>();

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }

    public int get(int key) {
        Integer value = element.get(key);

        if (value == null) {
            return -1;
        } else {
            //更新pool
            LFU(key);
            return value;
        }
    }

    public void put(int key, int value) {
        int size = element.size();

        if (capacity <= 0) return;


        if (!element.containsKey(key) && size >= capacity) {
            //LFU
            Node node = pool.remove(pool.size() - 1);//删除最后一个元素
            element.remove(node.key);
        }

        element.put(key, value);

        LFU(key);
    }

    private void LFU(int key) {
        Long date = Instant.now().toEpochMilli() + c++;
        if (pool.size() == 0) {
            pool.add(new Node(key, date, 1));
            return;
        } else {
            boolean isExist = false;
            for (Node node : pool) {
                if (node.key == key) {
                    node.count++;
                    node.times = date;
                    isExist = true;
                    continue;
                }
            }

            if (!isExist) {
                pool.add(new Node(key, date, 1));
            }
            Collections.sort(pool);
        }

    }


    static class Node implements Comparable<Node> {
        private int key;
        private Long times;
        private Integer count;

        public int getKey() {
            return key;
        }

        public void setKey(int key) {
            this.key = key;
        }

        public Long getTimes() {
            return times;
        }

        public void setTimes(Long times) {
            this.times = times;
        }

        public Integer getCount() {
            return count;
        }

        public void setCount(Integer count) {
            this.count = count;
        }

        public Node(int key, Long times, int count) {
            this.key = key;
            this.times = times;
            this.count = count;
        }

        @Override
        public int compareTo(Node o) {
            if (this.count.compareTo(o.count) == 0) {
                return o.times.compareTo(this.times);
            } else {
                return o.count.compareTo(this.count);
            }
        }
    }


}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
```