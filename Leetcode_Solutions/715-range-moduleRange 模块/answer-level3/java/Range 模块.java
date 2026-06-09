#### 方法一：维护有序的不相交区间

**分析**

我们尝试维护一个数据结构，存储有序的不相交区间。这里存储的区间都是闭区间（与题目中的半开区间不同），并且不会相交。例如，我们不会存储 $[[1, 2], [2, 3]]$，而是存储 $[[1,3]]$。

由于 Python 和 Java 支持的数据结构不相同，因此我们会对这两种语言分别给出一种算法。

**算法（Python）**

我们使用列表（list）`ranges` 来维护这个数据结构。

* addRange(): 当我们要添加一个区间 $[\mathrm{left}, \mathrm{right}]$ 时，我们首先使用二分查找，找到 $i$ 和 $j$，满足 `ranges[i: j + 1]` 中的所有区间和 $[\mathrm{left}, \mathrm{right}]$ 都相交。这里也可以直接使用线性查找，因为接下来的操作的时间复杂度是线性的。随后，我们将 `ranges[i: j + 1]` 中的所有区间替换成一个新的区间 `[min(left, sranges[i][0]), max(right, ranges[j][1])]`。

* removeRange()：当我们要删除一个区间 $[\mathrm{left}, \mathrm{right}]$ 时，我们同样先找到 $i$ 和 $j$，满足 `ranges[i: j + 1]` 中的所有区间和 $[\mathrm{left}, \mathrm{right}]$ 都相交。随后根据不同的情况，`ranges[i: j + 1]` 中的所有区间会被替换成 0，1，2 个新的区间。

* queryRange()：当我们要查找一个区间 $[\mathrm{left}, \mathrm{right}]$ 时，我们只需要进行二分查找，判断是否有一个区间包含了 $[\mathrm{left}, \mathrm{right}]$ 即可。

```Python []
class RangeModule(object):
    def __init__(self):
        self.ranges = []

    def _bounds(self, left, right):
        i, j = 0, len(self.ranges) - 1
        for d in (100, 10, 1):
            while i + d - 1 < len(self.ranges) and self.ranges[i+d-1][1] < left:
                i += d
            while j >= d - 1 and self.ranges[j-d+1][0] > right:
                j -= d
        return i, j

    def addRange(self, left, right):
        i, j = self._bounds(left, right)
        if i <= j:
            left = min(left, self.ranges[i][0])
            right = max(right, self.ranges[j][1])
        self.ranges[i:j+1] = [(left, right)]

    def queryRange(self, left, right):
        i = bisect.bisect_left(self.ranges, (left, float('inf')))
        if i: i -= 1
        return (bool(self.ranges) and
                self.ranges[i][0] <= left and
                right <= self.ranges[i][1])

    def removeRange(self, left, right):
        i, j = self._bounds(left, right)
        merge = []
        for k in xrange(i, j+1):
            if self.ranges[k][0] < left:
                merge.append((self.ranges[k][0], left))
            if right < self.ranges[k][1]:
                merge.append((right, self.ranges[k][1]))
        self.ranges[i:j+1] = merge
```

**算法（Java）**

我们使用基于平衡树的集合（TreeSet）`ranges` 来维护这个数据结构。`ranges` 内部的区间按照右端点从小到大排序。

* addRange()，removeRange(): 和 Python 的实现方法相同，我们遍历 `ranges` 里的所有区间，找到其中所有与 $[\mathrm{left}, \mathrm{right}]$ 重合的区间。如果需要添加区间 $[\mathrm{left}, \mathrm{right}]$，就删除这些重合的区间，并将 $[\mathrm{left}, \mathrm{right}]$ 添加到 `ranges` 中。如果需要删除区间，就在删除这些重合的区间的同时记录下出现的新区间，并在删除操作结束后把这 0，1，2 个新区间添加到 `ranges` 中。

* queryRange()：由于 `ranges` 是一颗平衡树，我们可以在对数时间复杂度内找出是否有一个区间包含 $[\mathrm{left}, \mathrm{right}]$。

```Java []
class RangeModule {
    TreeSet<Interval> ranges;
    public RangeModule() {
        ranges = new TreeSet();
    }

    public void addRange(int left, int right) {
        Iterator<Interval> itr = ranges.tailSet(new Interval(0, left - 1)).iterator();
        while (itr.hasNext()) {
            Interval iv = itr.next();
            if (right < iv.left) break;
            left = Math.min(left, iv.left);
            right = Math.max(right, iv.right);
            itr.remove();
        }
        ranges.add(new Interval(left, right));
    }

    public boolean queryRange(int left, int right) {
        Interval iv = ranges.higher(new Interval(0, left));
        return (iv != null && iv.left <= left && right <= iv.right);
    }

    public void removeRange(int left, int right) {
        Iterator<Interval> itr = ranges.tailSet(new Interval(0, left)).iterator();
        ArrayList<Interval> todo = new ArrayList();
        while (itr.hasNext()) {
            Interval iv = itr.next();
            if (right < iv.left) break;
            if (iv.left < left) todo.add(new Interval(iv.left, left));
            if (right < iv.right) todo.add(new Interval(right, iv.right));
            itr.remove();
        }
        for (Interval iv: todo) ranges.add(iv);
    }
}

class Interval implements Comparable<Interval>{
    int left;
    int right;

    public Interval(int left, int right){
        this.left = left;
        this.right = right;
    }

    public int compareTo(Interval that){
        if (this.right == that.right) return this.left - that.left;
        return this.right - that.right;
    }
}
```

**复杂度分析**

* 时间复杂度：设 $K$ 为 `ranges` 中的元素个数，那么 `addRange()` 和 `removeRange()` 的时间复杂度为 $O(K)$，`queryRange()` 的时间复杂度为 $O(\log K)$。更具体地，如果有 $A$ 次 `addRange()` 操作，$R$ 次 `removeRange()` 操作和 $Q$ 次 `queryRange()` 操作，那么总的时间复杂度为 $O((A+R)^2+Q\log(A+R))$。
* 空间复杂度：$O(A+R)$。