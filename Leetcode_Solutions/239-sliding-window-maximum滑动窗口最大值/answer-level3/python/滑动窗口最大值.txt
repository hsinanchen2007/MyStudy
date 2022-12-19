#### 方法一：暴力法

**直觉**

最简单直接的方法是遍历每个滑动窗口，找到每个窗口的最大值。一共有  `N - k + 1` 个滑动窗口，每个有 `k` 个元素，于是算法的时间复杂度为 ${O}(N k)$，表现较差。

**实现**

```Python [solution 1]
class Solution:
    def maxSlidingWindow(self, nums: 'List[int]', k: 'int') -> 'List[int]':
        n = len(nums)
        if n * k == 0:
            return []
        
        return [max(nums[i:i + k]) for i in range(n - k + 1)]
```

```Java [solution 1]
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        int n = nums.length;
        if (n * k == 0) return new int[0];
        
        int [] output = new int[n - k + 1];
        for (int i = 0; i < n - k + 1; i++) {
            int max = Integer.MIN_VALUE;
            for(int j = i; j < i + k; j++) 
                max = Math.max(max, nums[j]);
            output[i] = max;
        }
        return output;
    }
}
```

**复杂度分析**

* 时间复杂度：${O}(N k)$。其中 `N` 为数组中元素个数。
 
* 空间复杂度：${O}(N - k + 1)$，用于输出数组。
<br />
<br />


---
#### 方法二：双向队列

**直觉**

如何优化时间复杂度呢？首先想到的是使用**堆**，因为在最大堆中 `heap[0]` 永远是最大的元素。在大小为 `k` 的堆中插入一个元素消耗 $\log(k)$ 时间，因此算法的时间复杂度为 ${O}(N \log(k))$。

> 能否得到只要 ${O}(N)$ 的算法？

我们可以使用**双向队列**，该数据结构可以从两端以常数时间压入/弹出元素。

存储双向队列的索引比存储元素更方便，因为两者都能在数组解析中使用。

**算法**

算法非常直截了当：

- 处理前 `k` 个元素，初始化双向队列。

- 遍历整个数组。在每一步 :

    清理双向队列 :

        - 只保留当前滑动窗口中有的元素的索引。
    
        - 移除比当前元素小的所有元素，它们不可能是最大的。
        
* 将当前元素添加到双向队列中。
* 将 `deque[0]` 添加到输出中。
* 返回输出数组。

**实现**


```Python [solution 2]
from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: 'List[int]', k: 'int') -> 'List[int]':
        # base cases
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums
        
        def clean_deque(i):
            # remove indexes of elements not from sliding window
            if deq and deq[0] == i - k:
                deq.popleft()
                
            # remove from deq indexes of all elements 
            # which are smaller than current element nums[i]
            while deq and nums[i] > nums[deq[-1]]:
                deq.pop()
        
        # init deque and output
        deq = deque()
        max_idx = 0
        for i in range(k):
            clean_deque(i)
            deq.append(i)
            # compute max in nums[:k]
            if nums[i] > nums[max_idx]:
                max_idx = i
        output = [nums[max_idx]]
        
        # build output
        for i in range(k, n):
            clean_deque(i)          
            deq.append(i)
            output.append(nums[deq[0]])
        return output
```

```Java [solution 2]
class Solution {
  ArrayDeque<Integer> deq = new ArrayDeque<Integer>();
  int [] nums;

  public void clean_deque(int i, int k) {
    // remove indexes of elements not from sliding window
    if (!deq.isEmpty() && deq.getFirst() == i - k)
      deq.removeFirst();

    // remove from deq indexes of all elements 
    // which are smaller than current element nums[i]
    while (!deq.isEmpty() && nums[i] > nums[deq.getLast()])                           deq.removeLast();
  }

  public int[] maxSlidingWindow(int[] nums, int k) {
    int n = nums.length;
    if (n * k == 0) return new int[0];
    if (k == 1) return nums;

    // init deque and output
    this.nums = nums;
    int max_idx = 0;
    for (int i = 0; i < k; i++) {
      clean_deque(i, k);
      deq.addLast(i);
      // compute max in nums[:k]
      if (nums[i] > nums[max_idx]) max_idx = i;
    }
    int [] output = new int[n - k + 1];
    output[0] = nums[max_idx];

    // build output
    for (int i  = k; i < n; i++) {
      clean_deque(i, k);
      deq.addLast(i);
      output[i - k + 1] = nums[deq.getFirst()];
    }
    return output;
  }
}
```

**复杂度分析**

* 时间复杂度：${O}(N)$，每个元素被处理两次- 其索引被添加到双向队列中和被双向队列删除。
 
* 空间复杂度：${O}(N)$，输出数组使用了 ${O}(N - k + 1)$ 空间，双向队列使用了 ${O}(k)$。
<br />
<br />


---
#### 方法三: 动态规划

**直觉**

这是另一个 ${O}(N)$ 的算法。本算法的优点是不需要使用 `数组 / 列表` 之外的任何数据结构。

算法的思想是将输入数组分割成有 `k` 个元素的块。
若 `n % k != 0`，则最后一块的元素个数可能更少。

![image.png](https://pic.leetcode-cn.com/95c5c42bcedb9c417b96925e5204e5bdad34456e29bd1b61a41138abd80e4b0b-image.png){:width=500}
{:align=center}

开头元素为 `i` ，结尾元素为 `j` 的当前滑动窗口可能在一个块内，也可能在两个块中。

![image.png](https://pic.leetcode-cn.com/27af2b52e80803bcb7a8285dbd27cfa9292a6cf6dd0a6454454d6d3357da15c6-image.png){:width=500}
{:align=center}

情况 `1` 比较简单。 建立数组 `left`， 其中 `left[j]` 是从块的开始到下标 `j` 最大的元素，方向 `左->右`。

![image.png](https://pic.leetcode-cn.com/79cbfbefc4c891c337f6b5de8c29f9d3ab39883c92c084a46163f2fa4f0f1d37-image.png){:width=500}
{:align=center}

为了处理更复杂的情况 `2`，我们需要数组 `right`，其中 `right[j]` 是从块的结尾到下标 `j` 最大的元素，方向 `右->左`。`right` 数组和 `left` 除了方向不同以外基本一致。

![image.png](https://pic.leetcode-cn.com/b404188e760dd82a2bd4ebf4f6fe2e8b3c229bb506ed2f3cc8a01675744c351b-image.png){:width=500}
{:align=center}

两数组一起可以提供两个块内元素的全部信息。考虑从下标 `i` 到下标 `j`的滑动窗口。 根据定义，`right[i]` 是左侧块内的最大元素， `left[j]` 是右侧块内的最大元素。因此滑动窗口中的最大元素为 `max(right[i], left[j])`。

![image.png](https://pic.leetcode-cn.com/3074f1eb068151ebdebbf1b605234815c64d0bf7812d33c8eb5ba044ab625300-image.png){:width=500}
{:align=center}

**算法**

算法十分直截了当：

- 从左到右遍历数组，建立数组 `left`。

- 从右到左遍历数组，建立数组 `right`。

- 建立输出数组 `max(right[i], left[i + k - 1])`，其中 `i` 取值范围为 `(0, n - k + 1)`。

**实现**

<![image.png](https://pic.leetcode-cn.com/e793d5c8ede0be91804b291f1565ab90c980371879d6ec683d0a05c1b4f7e984-image.png),![image.png](https://pic.leetcode-cn.com/4a699746334bfd5548a8a2a920e5bcd2b2922f6c39ca0bf2a52bc741a8b9c10d-image.png),![image.png](https://pic.leetcode-cn.com/f20d788625572649bd3def127aafdd287eb9d958fdb7e8323183980a4721f7aa-image.png),![image.png](https://pic.leetcode-cn.com/df789ba3e0741df8493eaedbbb5cc483a5805e7f4fc65a5a16436749a29bd08b-image.png),![image.png](https://pic.leetcode-cn.com/f060cabc30a2f902c9be177070a68df07e9a1586aff921c4243dbc376c276738-image.png),![image.png](https://pic.leetcode-cn.com/263dd3579de8f15c38164db0e7c506d9269c657c34f50dff0512469867a26f78-image.png)>

```Python [solution 3]
class Solution:
    def maxSlidingWindow(self, nums: 'List[int]', k: 'int') -> 'List[int]':
        n = len(nums)
        if n * k == 0:
            return []
        if k == 1:
            return nums
        
        left = [0] * n
        left[0] = nums[0]
        right = [0] * n
        right[n - 1] = nums[n - 1]
        for i in range(1, n):
            # from left to right
            if i % k == 0:
                # block start
                left[i] = nums[i]
            else:
                left[i] = max(left[i - 1], nums[i])
            # from right to left
            j = n - i - 1
            if (j + 1) % k == 0:
                # block end
                right[j] = nums[j]
            else:
                right[j] = max(right[j + 1], nums[j])
        
        output = []
        for i in range(n - k + 1):
            output.append(max(left[i + k - 1], right[i]))
            
        return output
```

```Java [solution 3]
class Solution {
  public int[] maxSlidingWindow(int[] nums, int k) {
    int n = nums.length;
    if (n * k == 0) return new int[0];
    if (k == 1) return nums;

    int [] left = new int[n];
    left[0] = nums[0];
    int [] right = new int[n];
    right[n - 1] = nums[n - 1];
    for (int i = 1; i < n; i++) {
      // from left to right
      if (i % k == 0) left[i] = nums[i];  // block_start
      else left[i] = Math.max(left[i - 1], nums[i]);

      // from right to left
      int j = n - i - 1;
      if ((j + 1) % k == 0) right[j] = nums[j];  // block_end
      else right[j] = Math.max(right[j + 1], nums[j]);
    }

    int [] output = new int[n - k + 1];
    for (int i = 0; i < n - k + 1; i++)
      output[i] = Math.max(left[i + k - 1], right[i]);

    return output;
  }
}
```

**复杂度分析**

* 时间复杂度：${O}(N)$，我们对长度为 `N` 的数组处理了 `3`次。 
 
* 空间复杂度：${O}(N)$，用于存储长度为 `N` 的 `left` 和 `right` 数组，以及长度为 `N - k + 1`的输出数组。

