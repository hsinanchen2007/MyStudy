####  方法一：两个 set
幼稚的方法是根据第一个数组 `nums1` 迭代并检查每个值是否存在在 `nums2` 内。如果存在将值添加到输出。这样的方法会导致 $O(n \times m)$ 的时间复杂性，其中 `n` 和 `m` 是数组的长度。 

为了在线性时间内解决这个问题，我们使用集合 `set`，在 $O(1)$ 时间复杂度实现操作。

其思想是将两个数组转换为集合 `set`，然后迭代较小的集合检查是否存在在较大集合中。平均情况下，这种方法的时间复杂度为 $O(n+m)$。 

<![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/349/349_slide_5.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/349/349_slide_6.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/349/349_slide_7.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/349/349_slide_8.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/349/349_slide_9.png),![在这里插入图片描述](https://pic.leetcode-cn.com/Figures/349/349_slide_10.png)>

**实现：**

```Python []
class Solution:
    def set_intersection(self, set1, set2):
        return [x for x in set1 if x in set2]
        
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """  
        set1 = set(nums1)
        set2 = set(nums2)
        
        if len(set1) < len(set2):
            return self.set_intersection(set1, set2)
        else:
            return self.set_intersection(set2, set1)
```

```Java []
class Solution {
  public int[] set_intersection(HashSet<Integer> set1, HashSet<Integer> set2) {
    int [] output = new int[set1.size()];
    int idx = 0;
    for (Integer s : set1)
      if (set2.contains(s)) output[idx++] = s;

    return Arrays.copyOf(output, idx);
  }

  public int[] intersection(int[] nums1, int[] nums2) {
    HashSet<Integer> set1 = new HashSet<Integer>();
    for (Integer n : nums1) set1.add(n);
    HashSet<Integer> set2 = new HashSet<Integer>();
    for (Integer n : nums2) set2.add(n);

    if (set1.size() < set2.size()) return set_intersection(set1, set2);
    else return set_intersection(set2, set1);
  }
}
```

**复杂度分析**

* 时间复杂度：$O(m+n)$，其中 `n` 和 `m` 是数组的长度。$O(n)$ 的时间用于转换 `nums1` 在集合中，$O(m)$ 的时间用于转换 `nums2` 到集合中，并且平均情况下，集合的操作为 $O(1)$。 
* 空间复杂度：$O(m+n)$，最坏的情况是数组中的所有元素都不同。 


####  方法二：内置函数
内置的函数在一般情况下的时间复杂度是 $O(n+m)$ 且时间复杂度最坏的情况是 $O(n \times m)$ 。

在 Python 中提供了交集的操作，在 Java 提供了 `retainAll()`  函数.

**实现:**
```Python []
class Solution:
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """  
        set1 = set(nums1)
        set2 = set(nums2)
        return list(set2 & set1)
```

```Java []
class Solution {
  public int[] intersection(int[] nums1, int[] nums2) {
    HashSet<Integer> set1 = new HashSet<Integer>();
    for (Integer n : nums1) set1.add(n);
    HashSet<Integer> set2 = new HashSet<Integer>();
    for (Integer n : nums2) set2.add(n);

    set1.retainAll(set2);

    int [] output = new int[set1.size()];
    int idx = 0;
    for (int s : set1) output[idx++] = s;
    return output;
  }
}
```

**复杂度分析**

* 时间复杂度：一般情况下是 $O(m+n)$，最坏情况下是 $O(m \times n)$。
* 空间复杂度：最坏的情况是 $O(m+n)$，当数组中的元素全部不一样时。