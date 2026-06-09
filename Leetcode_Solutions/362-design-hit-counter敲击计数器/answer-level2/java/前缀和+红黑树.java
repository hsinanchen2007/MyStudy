### 解题思路
我们知道时间是**有序**的，所以对于时间区间的统计，可以利用到天生**有序**的数据结构，**TreeMap,也就是红黑树**。

每次敲击，把敲击时刻的次数+1，需要获取敲击时间累计次数时，取*(X分钟前*,timestamp]的一个前闭后开区间，将其次数遍历累加即可。

这样的思路虽然可以解决，但是我们少利用了一个条件，**时间戳是单调递增的**。

什么意思呢？因为时间是不会回头的，过去的时间不会在下一次又重新触发，之前的时间的敲击次数，就永远固定了。于是，我们可以把timestamp之前的敲击次数，全部累加到timestamp。这样，timestamp存储的次数，就是此时刻之前全部的敲击次数了。

这样做有什么好处呢？如果我们需要获取当前时间和X分钟之前的敲击次数，只需要把两个时间点的敲击次数相减，就能获取到(*X分钟前*,timestamp]的敲击次数之后，避免了遍历的累加运算，因为在记录数据的时候，我们已经累加起来了。

如果*X分钟前*的这个时间点没有数据，那怎么办呢？

很好办，如果*X分钟前*没有数据，那么我们找到时间**<=X分钟前**最近的那个时间点就行了。因为前缀和的思路，就是去掉**X分钟之前**这个时间点之前敲击次数，剩下的，就是当前timestamp到X分钟前的敲击次数了。

### 核心代码

记录前缀和
```
// 把上一次敲击时间次数累加到这一次，运用前缀和的思想
// 因为timestamp是递增的，所以上次的时间一定<=这次时间
Map.Entry<Integer,Integer> lastHitEntry = m_hitCountMap.floorEntry(timestamp);// 上次敲击时刻
int lastHit = lastHitEntry == null ? 0 : lastHitEntry.getValue();// 之前敲击次数之和
m_hitCountMap.put(timestamp,lastHit + 1);// 累加到当前时间敲击
```

前缀和区间获取
```
// X分钟前的时刻，利用前缀和获取敲击时间<=minTime的最接近时刻
Map.Entry<Integer,Integer> minEntry = m_hitCountMap.floorEntry(minTime);
// 上一次敲击的时刻
Map.Entry<Integer,Integer> maxEntry = m_hitCountMap.floorEntry(timestamp);
```


### 代码

```java
class HitCounter {

    // key 敲击时刻 value 在这一时刻之前的闭区间计数之和
    private TreeMap<Integer,Integer> m_hitCountMap;// 敲击计数treeMap
    private int m_lastHitTime = 0;// 上一次的敲击时刻

    /** Initialize your data structure here. */
    public HitCounter() {
        m_hitCountMap = new TreeMap<>();
    }

    /** Record a hit.
     @param timestamp - The current timestamp (in seconds granularity). */
    public void hit(int timestamp) {
        // 把上一次敲击时间次数累加到这一次，运用前缀和的思想
        // 因为timestamp是递增的，所以上次的时间一定<=这次时间
        Map.Entry<Integer,Integer> lastHitEntry = m_hitCountMap.floorEntry(timestamp);// 上次敲击时刻
        int lastHit = lastHitEntry == null ? 0 : lastHitEntry.getValue();// 之前敲击次数之和
        m_hitCountMap.put(timestamp,lastHit + 1);// 累加到当前时间敲击
    }

    /** Return the number of hits in the past 5 minutes.
     @param timestamp - The current timestamp (in seconds granularity). */
    public int getHits(int timestamp) {
        int minTime = timestamp - 300;
        // 5分钟前的时刻，利用前缀和获取敲击时间<=minTime的最接近时刻
        Map.Entry<Integer,Integer> minEntry = m_hitCountMap.floorEntry(minTime);
        // 上一次敲击的时刻
        Map.Entry<Integer,Integer> maxEntry = m_hitCountMap.floorEntry(timestamp);
        int min = minEntry == null ? 0 : minEntry.getValue();
        int max = maxEntry == null ? 0 : maxEntry.getValue();
        // 两者之差就是这个时间范围内的敲击次数
        return max - min;
    }
}

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
```