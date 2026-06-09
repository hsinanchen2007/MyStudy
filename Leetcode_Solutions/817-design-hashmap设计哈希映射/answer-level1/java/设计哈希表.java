#### 思路

哈希表是一个在不同语言中都有的通用数据结构。例如，Python 中的 `dict` 和 Java 中的 `Hashmap`。哈希表的特性是可以根据给出的 **key** 快速访问 **value**。

> 设计哈希表有两个问题需要去解决： _1). 如何设计哈希方法？_ 和 _2).如何避免哈希碰撞？_ 。 

- **1). 如何设计哈希方法？**：哈希方法会将键值映射到某块存储空间，一个好的哈希方法应该将不同的键值 **_均匀_** 地分布在存储空间中。

- **2). 如何避免哈希碰撞？**：哈希方法要将大量的键值映射到一个有限的空间里,这样就有可能会将不同的键值映射到同一个存储空间，这种情况称为 _'哈希碰撞'_ 。哈希碰撞是不可避免的，但可以用策略来解决哈希碰撞。

#### 方法一：取模 + 数组

**思路**

最简单的思路就是用模运算作为哈希方法，为了降低哈希碰撞的概率，通常取素数的模，例如 `模 2069`。

定义 **array** 数组作为存储空间，通过哈希方法计算数组下标。为了解决 _哈希碰撞_ （即键值不同，但映射下标相同），利用 **桶** 来存储所有对应的数值。桶可以用 `数组` 或 `链表` 来实现，在下面的具体实现中， Python 中用的是 `数组`，Java 中用的是 `链表`。


**算法**

定义哈希表方法，`get()`，`put()` 和 `remove()`，其中的寻址过程如下所示：

- 对于一个给定的 `键值`，利用哈希方法生成键值的哈希码，利用哈希码定位存储空间。对于每个哈希码，都能找到一个 **桶** 来存储该键值所对应的数值。 

- 在找到一个桶之后，通过遍历来检查该 `键值` 对是否已经存在。

![pic](https://pic.leetcode-cn.com/Figures/706/706_hashmap.png)

```python [solution1-Python]
class Bucket:
    def __init__(self):
        self.bucket = []

    def get(self, key):
        for (k, v) in self.bucket:
            if k == key:
                return v
        return -1

    def update(self, key, value):
        found = False
        for i, kv in enumerate(self.bucket):
            if key == kv[0]:
                self.bucket[i] = (key, value)
                found = True
                break

        if not found:
            self.bucket.append((key, value))

    def remove(self, key):
        for i, kv in enumerate(self.bucket):
            if key == kv[0]:
                del self.bucket[i]


class MyHashMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        # better to be a prime number, less collision
        self.key_space = 2069
        self.hash_table = [Bucket() for i in range(self.key_space)]


    def put(self, key, value):
        """
        value will always be non-negative.
        :type key: int
        :type value: int
        :rtype: None
        """
        hash_key = key % self.key_space
        self.hash_table[hash_key].update(key, value)


    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        hash_key = key % self.key_space
        return self.hash_table[hash_key].get(key)


    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: None
        """
        hash_key = key % self.key_space
        self.hash_table[hash_key].remove(key)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
```

```java [solution1-Java]
class Pair<U, V> {
  public U first;
  public V second;

  public Pair(U first, V second) {
    this.first = first;
    this.second = second;
  }
}


class Bucket {
  private List<Pair<Integer, Integer>> bucket;

  public Bucket() {
    this.bucket = new LinkedList<Pair<Integer, Integer>>();
  }

  public Integer get(Integer key) {
    for (Pair<Integer, Integer> pair : this.bucket) {
      if (pair.first.equals(key))
        return pair.second;
    }
    return -1;
  }

  public void update(Integer key, Integer value) {
    boolean found = false;
    for (Pair<Integer, Integer> pair : this.bucket) {
      if (pair.first.equals(key)) {
        pair.second = value;
        found = true;
      }
    }
    if (!found)
      this.bucket.add(new Pair<Integer, Integer>(key, value));
  }

  public void remove(Integer key) {
    for (Pair<Integer, Integer> pair : this.bucket) {
      if (pair.first.equals(key)) {
        this.bucket.remove(pair);
        break;
      }
    }
  }
}

class MyHashMap {
  private int key_space;
  private List<Bucket> hash_table;

  /** Initialize your data structure here. */
  public MyHashMap() {
    this.key_space = 2069;
    this.hash_table = new ArrayList<Bucket>();
    for (int i = 0; i < this.key_space; ++i) {
      this.hash_table.add(new Bucket());
    }
  }

  /** value will always be non-negative. */
  public void put(int key, int value) {
    int hash_key = key % this.key_space;
    this.hash_table.get(hash_key).update(key, value);
  }

  /**
   * Returns the value to which the specified key is mapped, or -1 if this map contains no mapping
   * for the key
   */
  public int get(int key) {
    int hash_key = key % this.key_space;
    return this.hash_table.get(hash_key).get(key);
  }

  /** Removes the mapping of the specified value key if this map contains a mapping for the key */
  public void remove(int key) {
    int hash_key = key % this.key_space;
    this.hash_table.get(hash_key).remove(key);
  }
}

/**
 * Your MyHashMap object will be instantiated and called as such: MyHashMap obj = new MyHashMap();
 * obj.put(key,value); int param_2 = obj.get(key); obj.remove(key);
 */
```


**复杂度**

- 时间复杂度：每个方法的时间复杂度都为 $O(\frac{N}{K})$，其中 $N$ 为所有可能键值的数量，$K$ 为哈希表中预定义桶的数量，在这里 $K$ 为 `2069`。这里我们假设键值是均匀地分布在所有桶中的，桶的平均大小为 $\frac{N}{K}$，在最坏情况下需要遍历完整个桶，因此时间复杂度为 $O(\frac{N}{K})$。

- 空间复杂度：$O(K+M)$，其中 $K$ 为哈希表中预定义桶的数量，$M$ 为哈希表中已插入键值的数量。