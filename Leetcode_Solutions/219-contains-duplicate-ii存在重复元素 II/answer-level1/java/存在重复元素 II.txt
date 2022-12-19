## 概述
这篇文章是为初级读者准备的，文章中会介绍了以下几种方法和数据结构：
线性搜索，二分搜索和散列表。

#### 方法一 （线性搜索） 【超时】

**思路**
将每个元素与它之前的 $k$ 个元素中比较查看它们是否相等。

**算法**

这个算法维护了一个 $k$ 大小的滑动窗口，然后在这个窗口里面搜索是否存在跟当前元素相等的元素。

```Java []
public boolean containsNearbyDuplicate(int[] nums, int k) {
    for (int i = 0; i < nums.length; ++i) {
        for (int j = Math.max(i - k, 0); j < i; ++j) {
            if (nums[i] == nums[j]) return true;
        }
    }
    return false;
}
// Time Limit Exceeded.
```

**时间复杂度分析**

* 时间复杂度：$O(n \min(k,n))$
每次搜索都要花费 $O(\min(k, n))$ 的时间，哪怕$k$比$n$大，一次搜索中也只需比较 $n$ 次。

* 空间复杂度：$O(1)$

#### 方法二 （二叉搜索树） 【超时】

**思路**

通过自平衡二叉搜索树来维护一个 $k$ 大小的滑动窗口。

**算法**

这个方法的核心在于降低方法一中搜索前 $k$ 个元素所耗费的时间。可以想一下，我们能不能用一个更复杂的数据结构来维持这个 $k$ 大小的滑动窗口内元素的有序性呢？考虑到滑动窗口内元素是严格遵守先进先出的，那么队列会是一个非常自然就能想到的数据结构。链表实现的队列可以支持在常数时间内的 `删除`，`插入`，然而 `搜索` 耗费的时间却是线性的，所以如果用队列来实现的话结果并不会比方法一更好。

一个更好的选择是使用自平衡二叉搜索树（BST)。 BST 中`搜索`，`删除`，`插入`都可以保持 $O(\log k)$ 的时间复杂度，其中 $k$ 是 BST 中元素的个数。在大部分面试中你都不需要自己去实现一个 BST，所以把 BST 当成一个黑盒子就可以了。大部分的编程语言都会在标准库里面提供这些常见的数据结构。在 Java 里面，你可以用 `TreeSet` 或者是 `TreeMap`。在 C++ STL 里面，你可以用 `std::set` 或者是 `std::map`。

假设你已经有了这样一个数据结构，伪代码是这样的：

* 遍历数组，对于每个元素做以下操作：
    * 在 BST 中搜索当前元素，如果找到了就返回 `true`。
    * 在 BST 中插入当前元素。
    * 如果当前 BST 的大小超过了 $k$，删除当前 BST 中最旧的元素。
* 返回 `false`。

```Java []
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new TreeSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
// Time Limit Exceeded.
```

**复杂度分析**

* 时间复杂度：$O(n \log (\min(k,n)))$
我们会做 $n$ 次 `搜索`，`删除`，`插入` 操作。每次操作将耗费对数时间，即为 $\log (\min(k, n))$。注意，虽然 $k$ 可以比 $n$ 大，但滑动窗口大小不会超过 $n$。

* 空间复杂度：$O(\min(n,k))$
只有滑动窗口需要开辟额外的空间，而滑动窗口的大小不会超过 $O(\min(n,k))$。

**注意事项**

这个算法在 $n$ 和 $k$ 很大的时候依旧会超时。

#### 方法三 （散列表） 【通过】

**思路**

用散列表来维护这个$k$大小的滑动窗口。

**算法**

在之前的方法中，我们知道了对数时间复杂度的 `搜索` 操作是不够的。在这个方法里面，我们需要一个支持在常量时间内完成 `搜索`，`删除`，`插入` 操作的数据结构，那就是散列表。这个算法的实现跟方法二几乎是一样的。

* 遍历数组，对于每个元素做以下操作：
    * 在散列表中搜索当前元素，如果找到了就返回 `true`。
    * 在散列表中插入当前元素。
    * 如果当前散列表的大小超过了 $k$， 删除散列表中最旧的元素。
* 返回 `false`。

```Java []
public boolean containsNearbyDuplicate(int[] nums, int k) {
    Set<Integer> set = new HashSet<>();
    for (int i = 0; i < nums.length; ++i) {
        if (set.contains(nums[i])) return true;
        set.add(nums[i]);
        if (set.size() > k) {
            set.remove(nums[i - k]);
        }
    }
    return false;
}
```

**复杂度分析**

* 时间复杂度：$O(n)$
我们会做 $n$ 次 `搜索`，`删除`，`插入` 操作，每次操作都耗费常数时间。

* 空间复杂度：$O(\min(n, k))$
开辟的额外空间取决于散列表中存储的元素的个数，也就是滑动窗口的大小 $O(\min(n,k))$。