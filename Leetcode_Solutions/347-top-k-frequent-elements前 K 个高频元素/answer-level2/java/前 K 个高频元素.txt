#### 方法 1：堆

**想法**

`k = 1` 时问题很简单，线性时间内就可以解决。只需要用哈希表维护元素出现频率，每一步更新最高频元素即可。

当 `k > 1` 就需要一个能够根据出现频率快速获取元素的数据结构，这就是优先队列。

首先建立一个元素值对应出现频率的哈希表。在 Java 中使用 `HashMap`，但需要手工填值。在 Python 中提供一个字典结构用作哈希表和在 `collections` 库中的 `Counter` 方法去构建我们需要的哈希表。

这个步骤需要 $O(N)$ 时间其中 $N$ 是列表中元素个数。

第二步建立堆，堆中添加一个元素的复杂度是 $O(\log(k))$，要进行 $N$ 次复杂度是 $O(N)$。

最后一步是输出结果，复杂度为 $O(k\log(k))$。

在 Python 中可以使用 `heapq` 库中的 `nlargest` [方法](https://hg.python.org/cpython/file/2.7/Lib/heapq.py#l203)，可以在相同时间内完成，但只需要一行代码解决。

<![1.png](https://pic.leetcode-cn.com/4155ee86a93437e3e97c26051fa9cf9dd8524306099f08ae1073eaad57cb3bc0-1.png),![2.png](https://pic.leetcode-cn.com/f355b6e6d76fccab2f2b874cdc009248a02badd8d906ef97197fe21effef257f-2.png),![3.png](https://pic.leetcode-cn.com/02b4ba46f1998841f15b9e49c35a33a0f02d41b3a4b09543fea549bcfa75e3b1-3.png),![4.png](https://pic.leetcode-cn.com/561698deee4cf6e015f2d7675b93298d4d03693ae94f6a0c639d4c642257bfd9-4.png),![5.png](https://pic.leetcode-cn.com/f637fa869f031dc419d2d5069d06897cabf64ab741384cd4b3ec5c1d44cc5874-5.png),![6.png](https://pic.leetcode-cn.com/a9d96837cd26c63a25f976c3bb5a8adcb657ca4cebc09cfb88c9b48d4747409a-6.png),![7.png](https://pic.leetcode-cn.com/9c91828d3e5148d871c7a23a09e2a01a090c7753adf4e1746a5ec4fa1465e41b-7.png),![8.png](https://pic.leetcode-cn.com/933940bb7826b91ae778c3c6cb03ec126e11a53eb054b46d0f801809804f7a27-8.png),![9.png](https://pic.leetcode-cn.com/6042da7ca897f1786253c0f912d9900336577bf72141e848cb30f44f2f541dc6-9.png),![10.png](https://pic.leetcode-cn.com/24622621a7be3f475be38c95d13779984631ed99496e91cf4358c3403beeb544-10.png),![11.png](https://pic.leetcode-cn.com/b0ff8900eddeaf8b85e5b03a0ae91a49449b315a8fda7b6e03434c9ba374b757-11.png),![12.png](https://pic.leetcode-cn.com/f1395b1ed88ad7c3c2e76b24b29b3b8d88e992b8338aadf9d14de9da3349969e-12.png),![13.png](https://pic.leetcode-cn.com/ace094402432ad08005f17c02525d841bd2744ab98039eade6fb10968453e718-13.png),![14.png](https://pic.leetcode-cn.com/bac7c7fd0f87a8f4c6ccb329bcb4590683862db937c66d18cdd034effbaaaaa1-14.png)>
















```java [-Java]
class Solution {
  public List<Integer> topKFrequent(int[] nums, int k) {
    // build hash map : character and how often it appears
    HashMap<Integer, Integer> count = new HashMap();
    for (int n: nums) {
      count.put(n, count.getOrDefault(n, 0) + 1);
    }

    // init heap 'the less frequent element first'
    PriorityQueue<Integer> heap =
            new PriorityQueue<Integer>((n1, n2) -> count.get(n1) - count.get(n2));

    // keep k top frequent elements in the heap
    for (int n: count.keySet()) {
      heap.add(n);
      if (heap.size() > k)
        heap.poll();
    }

    // build output list
    List<Integer> top_k = new LinkedList();
    while (!heap.isEmpty())
      top_k.add(heap.poll());
    Collections.reverse(top_k);
    return top_k;
  }
}
```

```python [-Python]
class Solution:
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """ 
        count = collections.Counter(nums)   
        return heapq.nlargest(k, count.keys(), key=count.get) 
```

**复杂度分析**

* 时间复杂度：$O(N\log(k))$。`Counter` 方法的复杂度是 $O(N)$，建堆和输出的复杂度是 $O(N \log(k))$。因此总复杂度为 $O(N + N \log(k)) = O(N \log(k))$。
* 空间复杂度：$O(N)$，存储哈希表的开销。

**注释**

根据复杂度分析，方法对于小 `k` 的情况是很优的。但是如果 `k` 值很大，我们可以将算法改成删除频率最低的若干个元素。