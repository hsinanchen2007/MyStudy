### 解题思路
此处撰写解题思路

### 代码

```java
class LRUCache {

        private LinkedHashMap<Integer, Integer> hashMap;
        private int capacity;

        public LRUCache(int capacity) {
            this.capacity = capacity;
            // accessOrder: 默认为false表示按插入顺序排序， true表示按访问顺序排序
            hashMap = new LinkedHashMap<Integer, Integer>(capacity, 0.75F,true) {
                @Override
                protected boolean removeEldestEntry(Map.Entry<Integer, Integer> eldest) {
                    return size() > capacity;
                }
            };
        }

        public int get(int key) {
            return hashMap.getOrDefault(key, -1);
        }

        public void put(int key, int value) {
            hashMap.put(key, value);
        }

}

```