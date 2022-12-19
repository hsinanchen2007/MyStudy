# 思路
主要就是使用二分查找找到相应下标。

# 代码
```java
class StreamRank {
    private ArrayList<Integer> list;

    public StreamRank() {
        list = new ArrayList<>(50000);
    }

    public void track(int x) {
        int idx = Collections.binarySearch(list, x);
        if (idx < 0) idx = -idx - 1;
        list.add(idx, x);
    }

    public int getRankOfNumber(int x) {
        int idx = Collections.binarySearch(list, x);
        if (idx < 0) idx = -idx - 1;
        while (idx < list.size() && list.get(idx) <= x)
            ++idx;
        return idx;
    }
}
```
