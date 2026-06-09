####  方法一：线性搜索
**算法：**

由于引用次数列表是按升序排序的，因此我们可以再一次迭代过程中解决该问题。

让我们思考一篇引用次数为 `c` 的文章，它的索引是 `i`，即 `c = citations[i]`。我们可以知道，引用次数高于 `c` 的文章数量是 `n-i-1`。加上当前文章，有 `n-i` 个文章引用次数至少为 `c` 次。

根据 H 指数的定义，我们只需要找到第一篇文章 `c = citation[i]` 大于或等于 `n - i`，即 `c >= n - i`。我们知道在次之后的文章都引用次数至少 `c` 次，因此总共有 `n-i` 篇文章引用次数至少为 `c` 次。因此，根据定义，H 指数应该是 `n-i`。

![在这里插入图片描述](https://pic.leetcode-cn.com/61dc161d9dee7e378923237c2a0a7ff017c3aa2b162655584b9bfa09aefc9f76-file_1579413554342){:width=500}
{:align=center}


```python [solution1-Python]
class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        for idx, c in enumerate(citations):
            if c >= n - idx:
                return n - idx
        return 0
```

```java [solution1-Java]
class Solution {
  public int hIndex(int[] citations) {
    int idx = 0, n = citations.length;
    for(int c : citations) {
      if (c >= n - idx) return n - idx;
      else idx++;
    }
    return 0;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$，其中 $N$ 指的是输入数组的长度，最坏的情况下我们要遍历整个数组。
* 空间复杂度：$\mathcal{O}(1)$，这是一个常数空间的解决方法。


####  方法二：二分搜索
根据我们在方法一中的阐述，问题实际上可以归结为：给定一个大小为 `n` 的升序的引用次数列表，要求找到满足 `citations[i] >= n - i` 的第一个 `citations[i]`。

通过问题的转换，我们可以用二分搜索来解决该问题。在二分搜索算法中，我们递归的将搜索范围减半，与线性搜索相比，时间复杂度更优为 $\mathcal{O}(\log N)$。

![在这里插入图片描述](https://pic.leetcode-cn.com/d2f8f38faf2eb3e792dfa777394e784ea45485e7705729719dabc25eafa32f84-file_1579413554392){:width=500}
{:align=center}


**算法：**

- 首先，我们先获取列表的中间元素，即 `citations[pivot]`，它将原始列表分成了两个子列表：`citations[0 : pivot - 1]` 和 `citations[pivot + 1 : n]`。
- 然后比较 `n - pivot` 和 `citations[pivot]` 的值，二分搜索算法分为以下 3 种情况：
- 若 `citations[pivot] == n - pivot`：则我们找到了想要的元素。
- 若 `citations[pivot] < n - pivot`：由于我们想要的元素应该大于或等于 `n - pivot`，所以我们应该进一步搜索右边的子列表，即 `citations[pivot + 1 : n]`。
- 若 `citations[pivot] > n - pivot`：我们应该进一步搜索左边的子列表，即 `citations[0 : pivot-1]`。

与典型的二分搜索算法的一个小区别就是，我们返回的结果是 `n - pivot`，而不是所需元素的值。

```python [solution2-Python]
class Solution:
    def hIndex(self, citations):
        """
        :type citations: List[int]
        :rtype: int
        """
        n = len(citations)
        left, right = 0, n - 1
        while left <= right:
            pivot = left + (right - left) // 2
            if citations[pivot] == n - pivot:
                return n - pivot
            elif citations[pivot] < n - pivot:
                left = pivot + 1
            else:
                right = pivot - 1
        
        return n - left
```

```java [solution2-Java]
class Solution {
  public int hIndex(int[] citations) {
    int idx = 0, n = citations.length;
    int pivot, left = 0, right = n - 1;
    while (left <= right) {
      pivot = left + (right - left) / 2;
      if (citations[pivot] == n - pivot) return n - pivot;
      else if (citations[pivot] < n - pivot) left = pivot + 1;
      else right = pivot - 1;
    }
    return n - left;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log N)$，由于使用了二分搜索算法。
* 空间复杂度：$\mathcal{O}(1)$，这是一个常数空间的解决方法。