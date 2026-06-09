####  概述
我们需要实现三个操作：
1. `insert`
2. `remove`
3. `getRadom`

 `getRandom` 时间复杂度为 $O(1)$，并出现的概率与值的副本数成线性比例。最简单的解决方案是将所有值存储在一个列表中。一旦存储了所有值，我们所要做的就是选择一个随机索引。

我们并不关心元素的顺序，所以可以使用动态数组（Java 中的 `ArrayList` 或 Python 中的 `list`）在 $O(1)$ 的时间执行 `insert`。

由于我们不关心元素的顺序，如果我们想删除第 `i` 个索引处的元素，我们可以交换第 `i` 个元素和最后一个元素，并执行 $O(1)$ 的 `pop` 操作（事实上我们不需要交换，我们只需要将最后一个元素复制到索引 `i` 中，再弹出最后一个元素）。

问题中最困难的部分就是要在 $O(1)$  的时间找到要删除元素的索引。我们可以通过一个哈希表将元素值映射到它们的索引。

####  方法：动态数组 + 哈希表
**算法：**

我们将用列表来存储所有元素。为了找到要删除元素的索引，我们将使用 `HashMap` 或 `dictionary` 将值映射到具有这些值的所有索引。困难的部分是在修改列表时正确地更新 `HashMap`。

- `insert`：添加元素到 `list`，并在 `HaspMap` 表中添加对应的索引。
- `remove`：这是比较困难的部分，我们使用`HashMap` 找到要删除元素的索引。使用概述中的方法实现 $O(1)$ 时间删除元素。由于列表中的最后一个元素被移动，我们要更新 `HashMap` 中的最后一个元素对应的索引值，还要删除 `HashMap` 中要删除元素的索引。
- `getRadom`：从列表中随机抽取一个元素。

```python [solution1-Python]
from collections import defaultdict
from random import choice

class RandomizedCollection:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.lst = []
        self.idx = defaultdict(set)


    def insert(self, val: int) -> bool:
        """
        Inserts a value to the collection. Returns true if the collection did not already contain the specified element.
        """
        self.idx[val].add(len(self.lst))
        self.lst.append(val)
        return len(self.idx[val]) == 1


    def remove(self, val: int) -> bool:
        """
        Removes a value from the collection. Returns true if the collection contained the specified element.
        """
        if not self.idx[val]: return False
        remove, last = self.idx[val].pop(), self.lst[-1]
        self.lst[remove] = last
        self.idx[last].add(remove)
        self.idx[last].discard(len(self.lst) - 1)

        self.lst.pop()
        return True


    def getRandom(self) -> int:
        """
        Get a random element from the collection.
        """
        return choice(self.lst)
```

```java [solution1-Java]
public class RandomizedCollection {
    ArrayList<Integer> lst;
    HashMap<Integer, Set<Integer>> idx;
    java.util.Random rand = new java.util.Random();
    /** Initialize your data structure here. */

    public RandomizedCollection() {
        lst = new ArrayList<Integer>();
	      idx = new HashMap<Integer, Set<Integer>>();
    }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    public boolean insert(int val) {
        if (!idx.containsKey(val)) idx.put(val, new LinkedHashSet<Integer>());
        idx.get(val).add(lst.size());
        lst.add(val);
        return idx.get(val).size() == 1;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    public boolean remove(int val) {
        if (!idx.containsKey(val) || idx.get(val).size() == 0) return false;
	      int remove_idx = idx.get(val).iterator().next();
        idx.get(val).remove(remove_idx);
        int last = lst.get(lst.size() - 1);
        lst.set(remove_idx, last);
        idx.get(last).add(remove_idx);
        idx.get(last).remove(lst.size() - 1);

	      lst.remove(lst.size() - 1);
        return true;
    }

    /** Get a random element from the collection. */
    public int getRandom() {
        return lst.get(rand.nextInt(lst.size()));
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 指的是操作的数量，每个操作 $O(1)$，则 $N * O(1) = O(N)$
* 空间复杂度：$O(N)$，$N$ 指的是操作的数量，最坏的情况下是执行了 $N$ 次 `insert` 操作，则 `ArrayList` 和 `HashMap` 大小均为 $N$。