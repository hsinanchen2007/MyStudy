#### 方法一：HashMap + 二分查找

**思路与算法**

对于每一个键值 `key` 的两种操作，我们只关注键值的时间戳与值信息。我们可以将这些信息存储在一个 `HashMap` 中。

对于每一个键值 `key`，我们可以在已经按照时间戳排序好的序列中进行二分检索，从而找到对应 `key` 相关的 `value`。

```java [orMEF9kM-Java]
import javafx.util.Pair;

class TimeMap {
    Map<String, List<Pair<Integer, String>>> M;

    public TimeMap() {
        M = new HashMap();
    }

    public void set(String key, String value, int timestamp) {
        if (!M.containsKey(key))
            M.put(key, new ArrayList<Pair<Integer, String>>());

        M.get(key).add(new Pair(timestamp, value));
    }

    public String get(String key, int timestamp) {
        if (!M.containsKey(key)) return "";

        List<Pair<Integer, String>> A = M.get(key);
        int i = Collections.binarySearch(A, new Pair<Integer, String>(timestamp, "{"),
                (a, b) -> Integer.compare(a.getKey(), b.getKey()));

        if (i >= 0)
            return A.get(i).getValue();
        else if (i == -1)
            return "";
        else
            return A.get(-i-2).getValue();
    }
}
```
```python [orMEF9kM-Python]
class TimeMap(object):
    def __init__(self):
        self.M = collections.defaultdict(list)

    def set(self, key, value, timestamp):
        self.M[key].append((timestamp, value))

    def get(self, key, timestamp):
        A = self.M.get(key, None)
        if A is None: return ""
        i = bisect.bisect(A, (timestamp, chr(127)))
        return A[i-1][1] if i else ""
```


**复杂度分析**

* 时间复杂度：对于 `set` 操作，$O(1)$ 。对于 `get` 操作，$O(\log N)$。 其中，$N$ 是 `TimeMap` 中元素的数量。

* 空间复杂度：$O(N)$。





---
#### 方法二：TreeMap

**思路与算法**

对于 `Java` 语言，我们可以使用 `TreeMap.floorKey(timestamp)` 来找到小于等于给定时间戳 `timestamp` 的最大时间戳。

我们使用与 *方法一* 相同的方法构建解法，仅仅替换这部分的功能。

```java [4bgysnDB-Java]
class TimeMap {
    Map<String, TreeMap<Integer, String>> M;

    public TimeMap() {
        M = new HashMap();
    }

    public void set(String key, String value, int timestamp) {
        if (!M.containsKey(key))
            M.put(key, new TreeMap());

        M.get(key).put(timestamp, value);
    }

    public String get(String key, int timestamp) {
        if (!M.containsKey(key)) return "";

        TreeMap<Integer, String> tree = M.get(key);
        Integer t = tree.floorKey(timestamp);
        return t != null ? tree.get(t) : "";
    }
}
```


**复杂度分析**

* 时间复杂度：对于 `set` 操作，$O(1)$。对于 `get` 操作，$O(\log N)$。其中，$N​$ 是 `TimeMap` 中元素的数量。

* 空间复杂度：$O(N)$。



