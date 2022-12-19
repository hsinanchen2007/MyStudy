#### 方法一：时间戳转换

在比较两个时间戳的大小时，直接使用字符串比较会非常麻烦，因此我们可以考虑将时间戳直接转换成一个整数，并保持原本的偏序关系。

一种比较显然的方法是，我们可以将时间戳转换为从公元元年开始到该时间戳的秒数，但这个数字可能会比较大。由于本题中年份的限制在 `[2000, 2017]` 之间，因此我们可以将时间戳转换为从 1999 年开始到该时间戳的秒数。为了转换更加方便，我们可以将每个月都看成 31 天，这样偏序关系仍然能够保持，只是有些整数没有对应的时间戳而已。对于题目中要求的两个操作，我们用如下的方法实现：

- `put(id, timestamp)`：我们首先将时间戳转换为整数（即从 1999 年开始的秒数），随后将其连同 `id` 一起放入数组中；

- `retrieve(start, end, granularity)`：我们首先根据粒度（granularity）将开始和结束时间戳转换为整数，即对于粗粒度的时间级，我们保留 `start` 或 `end` 中对应的时间不变，对于细粒度的时间级，我们将 `start` 中对应的时间置零，`end` 中对应的时间置为最大值。随后我们遍历所数组中所有的日志，依次判断每条日志的时间是否在 `[start, end]` 中。

```Java [sol1]
public class LogSystem {
    ArrayList < long[] > list;
    public LogSystem() {
        list = new ArrayList < long[] > ();
    }

    public void put(int id, String timestamp) {
        int[] st = Arrays.stream(timestamp.split(":")).mapToInt(Integer::parseInt).toArray();
        list.add(new long[] {convert(st), id});
    }
    public long convert(int[] st) {
        st[1] = st[1] - (st[1] == 0 ? 0 : 1);
        st[2] = st[2] - (st[2] == 0 ? 0 : 1);
        return (st[0] - 1999L) * (31 * 12) * 24 * 60 * 60 + st[1] * 31 * 24 * 60 * 60 + st[2] * 24 * 60 * 60 + st[3] * 60 * 60 + st[4] * 60 + st[5];
    }
    public List < Integer > retrieve(String s, String e, String gra) {
        ArrayList < Integer > res = new ArrayList();
        long start = granularity(s, gra, false);
        long end = granularity(e, gra, true);
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i)[0] >= start && list.get(i)[0] < end)
                res.add((int) list.get(i)[1]);
        }
        return res;
    }

    public long granularity(String s, String gra, boolean end) {
        HashMap < String, Integer > h = new HashMap();
        h.put("Year", 0);
        h.put("Month", 1);
        h.put("Day", 2);
        h.put("Hour", 3);
        h.put("Minute", 4);
        h.put("Second", 5);
        String[] res = new String[] {"1999", "00", "00", "00", "00", "00"};
        String[] st = s.split(":");
        for (int i = 0; i <= h.get(gra); i++) {
            res[i] = st[i];
        }
        int[] t = Arrays.stream(res).mapToInt(Integer::parseInt).toArray();
        if (end)
            t[h.get(gra)]++;
        return convert(t);
    }
}
```

**复杂度分析**

我们这里只分析时间复杂度，并且假设将时间戳转换为整数的时间复杂度为 $O(1)$。

对于 `put` 操作，时间复杂度为 $O(1)$。对于 `retrieve` 操作，由于需要遍历所有日志，因此时间复杂度为 $O(N)$，其中 $N$ 是日志的总数。

#### 方法二：时间戳转换 + 有序哈希映射

方法一中 `retrieve` 操作的时间复杂度非常高，我们希望得到一种时间复杂度和返回的日志数目成正比的方法。因此我们可以对 `put` 和 `retrieve` 操作做一个权衡，在略微增加 `put` 操作的时间复杂度的同时，降低 `retrieve` 操作的时间复杂度。

我们可以使用有序的哈希映射（TreeMap），在 `put` 操作中，我们将时间戳对应的整数和 `id` 放入哈希映射中，并使得它们关于整数有序。在 `retrieve` 操作中，我们可以根据 `start` 对应的整数，在哈希映射中定位第一个（即最早的不早于 `start` 出现的日志），并遍历哈希映射，直到遇到一个晚于 `end` 出现的日志。

```Java [sol2]
public class LogSystem {
    TreeMap < Long, Integer > map;
    public LogSystem() {
        map = new TreeMap < Long, Integer > ();
    }

    public void put(int id, String timestamp) {
        int[] st = Arrays.stream(timestamp.split(":")).mapToInt(Integer::parseInt).toArray();
        map.put(convert(st), id);
    }
    public long convert(int[] st) {
        st[1] = st[1] - (st[1] == 0 ? 0 : 1);
        st[2] = st[2] - (st[2] == 0 ? 0 : 1);
        return (st[0] - 1999L) * (31 * 12) * 24 * 60 * 60 + st[1] * 31 * 24 * 60 * 60 + st[2] * 24 * 60 * 60 + st[3] * 60 * 60 + st[4] * 60 + st[5];
    }
    public List < Integer > retrieve(String s, String e, String gra) {
        ArrayList < Integer > res = new ArrayList();
        long start = granularity(s, gra, false);
        long end = granularity(e, gra, true);
        for (long key: map.tailMap(start).keySet()) {
            if (key >= start && key < end)
                res.add(map.get(key));
        }
        return res;
    }

    public long granularity(String s, String gra, boolean end) {
        HashMap < String, Integer > h = new HashMap();
        h.put("Year", 0);
        h.put("Month", 1);
        h.put("Day", 2);
        h.put("Hour", 3);
        h.put("Minute", 4);
        h.put("Second", 5);
        String[] res = new String[] {"1999", "00", "00", "00", "00", "00"};
        String[] st = s.split(":");
        for (int i = 0; i <= h.get(gra); i++) {
            res[i] = st[i];
        }
        int[] t = Arrays.stream(res).mapToInt(Integer::parseInt).toArray();
        if (end)
            t[h.get(gra)]++;
        return convert(t);
    }
}
```

**复杂度分析**

我们这里只分析时间复杂度，并且假设将时间戳转换为整数的时间复杂度为 $O(1)$。

对于 `put` 操作，时间复杂度为 $O(\log N)$。对于 `retrieve` 操作，由于在 TreeMap 中找到下一个元素的均摊复杂度为 $O(1)$，因此总时间复杂度为 $O(M)$，其中 $M$ 为该操作返回的日志的数目。