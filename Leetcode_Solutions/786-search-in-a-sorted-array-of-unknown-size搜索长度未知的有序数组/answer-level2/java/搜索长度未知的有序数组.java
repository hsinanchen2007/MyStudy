####  方法一：二分查找
划分为两个子问题：
- 定义搜索范围，即搜索的左边界和有边界。
- 在定义的边界内执行二分查找。

![在这里插入图片描述](https://pic.leetcode-cn.com/d0c52952ab03ed61b0add2a78f851716830eef975ba38077bfa01d9e2b129b32-file_1578973095306){:width=500}

**定义搜索边界：**

这是一个关键的子问题，让我们把前两个索引 `0` 和 `1` 作为左右边界。如果目标值不在第 `0` 个元素和第 `1` 个元素之间，那么它就在有边界的边界之外。

这意味着左边界可以向右移动，有边界应该扩展，为了保证对数时间的复杂度，我们将有边界扩展到两倍：`right = right * 2`。

![在这里插入图片描述](https://pic.leetcode-cn.com/cb9a3fdaf0b50768cee2fcfb10a8978cba2d00d43ca70d74ab8c480277cbcabc-file_1578973095297){:width=500}

如果目标值小于右边界的元素，则说明搜索边界设置好了。否则重复这两个步骤，直到确定边界：
- 将左边界移动到右边界：`left = right`。
- 扩展右边界：`right = right * 2`。

![在这里插入图片描述](https://pic.leetcode-cn.com/9d3a7964f00d5c0a6cb1692c93601da192907dce5162c5b27c3bae8fea48b7e0-file_1578973095270){:width=500}

**二分查找：**

二分查找是具有对数时间复杂度的教科书式算法，它的基础思想是将目标值 `target` 与数组中间的元素 `mid` 进行比较。
- 如果 `target == mid`，则在数组中找到了目标值。
- 如果 `target < mid`，则左半部分数组继续查找。
- 如果 `target > mid`，则右半部分数组继续查找。

![在这里插入图片描述](https://pic.leetcode-cn.com/8b22ee0f49ad835b23a682616a1371a76d663cc7e27290f6ac0091c9ea34b0a3-file_1578973095301){:width=500}

为了加快速度，我们可以使用位移运算：
- 左移：`x << 1`，与 `x * 2` 的作用相同。
- 右移：`x >> 1`，与 `x / 2` 的作用相同。

**算法：**

**定义搜索边界：**

- 初始化 `left = 0` 和 `right = 1`。
- 若目标值在搜索边界的右边，即 `reader.get(right) < target`：
	- 将左边界移动到右边界：`left = right`。
	- 扩展右边界：`right *= 2`，为了加快速度，我们使用有移代替：`right <<= 1`。
- 直到目标值在搜索边界内。  

**二分查找：**

- 当 `left <= right`：
	-  获取搜索边界的中间元素索引 `pivot = (left + right) / 2`。为了避免溢出，使用 `pivot = left + ((right - left) >> 1)` 代替。
	- 获取中间元素：`num = reader.get(pivot)`。
	- 比较目标值和中间元素：
		- 如果 `num == target`：返回 `pivot`。
		- 如果 `num > target`，则 `right = pivot -1`。
		- 如果 `num < target`，则 `left = pivot +1`。
- 未找到目标值，返回 -1。

```python [solution1-Python]
class Solution:
    def search(self, reader, target):
        if reader.get(0) == target:
            return 0
        
        # search boundaries
        left, right = 0, 1
        while reader.get(right) < target:
            left = right
            right <<= 1
        
        # binary search
        while left <= right:
            pivot = left + ((right - left) >> 1)
            num = reader.get(pivot)
            
            if num == target:
                return pivot
            if num > target:
                right = pivot - 1
            else:
                left = pivot + 1
        
        # there is no target element
        return -1
```

```java [solution1-Java]
class Solution {
  public int search(ArrayReader reader, int target) {
    if (reader.get(0) == target) return 0;

    // search boundaries
    int left = 0, right = 1;
    while (reader.get(right) < target) {
      left = right;
      right <<= 1;
    }

    // binary search
    int pivot, num;
    while (left <= right) {
      pivot = left + ((right - left) >> 1);
      num = reader.get(pivot);

      if (num == target) return pivot;
      if (num > target) right = pivot - 1;
      else left = pivot + 1;
    }

    // there is no target element
    return -1;
  }
}
```

```c++ [solution1-C++]
class ArrayReader;

class Solution {
  public:
  int search(const ArrayReader& reader, int target) {
    if (reader.get(0) == target) return 0;

    // search boundaries
    int left = 0, right = 1;
    while (reader.get(right) < target) {
      left = right;
      right <<= 1;
    }

    // binary search
    int pivot, num;
    while (left <= right) {
      pivot = left + ((right - left) >> 1);
      num = reader.get(pivot);

      if (num == target) return pivot;
      if (num > target) right = pivot - 1;
      else left = pivot + 1;
    }

    // there is no target element
    return -1;
  }
};
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log T)$。其中 $T$ 是目标值的索引。
* 空间复杂度：$O(1)$。