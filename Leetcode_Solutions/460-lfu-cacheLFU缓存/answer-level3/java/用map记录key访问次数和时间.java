### 解题思路
1. 用map记录key访问次数和时间
2. 考虑要获取最小访问次数和最远时间的key（LFU），用的JDK api中的Collections.min效率不太高。要么在加一个排序数据结构记录顺序


### 代码

```java
class LFUCache {
    private Map<Integer, Integer> map = new HashMap<>();
    private Map<Integer, AccessHistory> freqMap = new HashMap<>();
    private int capacity;

    public LFUCache(int capacity) {
        this.capacity = capacity;
    }
    
    public int get(int key) {
        Integer v = map.get(key);
        if(v != null) {
            addAccessHistory(key);
        } else {
            return -1;
        }

        return v;
    }
    
    public void put(int key, int value) {
        if(this.capacity < 1) {
            return;
        }

        Integer v = map.get(key);
        if(v != null) {
            map.put(key, value);
            addAccessHistory(key);
        } else {
            if(map.size() >= this.capacity) {
                removeOldest();
            }
            map.put(key, value);
            AccessHistory ah = new AccessHistory(key, 1, System.nanoTime());
            freqMap.put(key, ah);
        }
    }

    public void addAccessHistory(int key) {
            AccessHistory ah = freqMap.get(key);
            if(ah != null) {
                ah.setCnt(ah.getCnt() + 1);
                ah.setAccessTime(System.nanoTime());
                // System.out.println("key:" + key + ", cnt:" + ah.getCnt() + ", time:" + ah.getAccessTime());
            }
    }
    public void removeOldest() {
        AccessHistory ah = Collections.min(freqMap.values());

        // System.out.println("remove key:" + ah.getKey());
        map.remove(ah.getKey());
        freqMap.remove(ah.getKey());
    }

    class AccessHistory implements Comparable {
        private int key;
        private int cnt; //access count times
        private long accessTime; // acess time

        public AccessHistory(int key, int cnt, long accessTime) {
            this.key = key;
            this.cnt = cnt;
            this.accessTime = accessTime;
        }

        public int getKey() {
            return this.key;
        }

        public void setCnt(int cnt) {
            this.cnt = cnt;
        }

        public int getCnt() {
            return cnt;
        }

        public void setAccessTime(long accessTime) {
            this.accessTime = accessTime;
        }

        public long getAccessTime() {
            return this.accessTime;
        }

        public int compareTo(Object o) {
            AccessHistory ah = (AccessHistory)o;

            int result = this.cnt - ah.getCnt();
            if(result > 0) {
                return 1;
            } else if(result < 0) {
                return -1;
            } else {
                return  this.accessTime > ah.getAccessTime() ? 1 :  (this.accessTime < ah.getAccessTime() ? -1 : 0);
            }
        }

        public boolean equals(Object o) {
            if(o == this) {
                return true;
            }

            if(!(o instanceof AccessHistory)) {
                return false;
            }

            return key == ((AccessHistory)o).getKey();
        }

        public final int hashCode() {
            int result = 17;

            return 31 * result + key;
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