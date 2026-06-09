####  概述
使用哈希表可以在 $\mathcal{O}(N)$ 的时间复杂度和 $\mathcal{O}(N)$ 的空间复杂度中解决该问题。

这个问题在常数的空间复杂度中解决有点困难，但可以借助两个位掩码来实现。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjYwL3R3bzIucG5n?x-oss-process=image/format,png)
####  方法一：哈希表
建立一个值到频率的映射关系的哈希表，返回频率为 1 的数字。

**算法：**

```python [solution1-Python]
from collections import Counter
class Solution:
    def singleNumber(self, nums: int) -> List[int]:
        hashmap = Counter(nums)
        return [x for x in hashmap if hashmap[x] == 1]
```

```java [solution1-Java]
class Solution {
  public int[] singleNumber(int[] nums) {
    Map<Integer, Integer> hashmap = new HashMap();
    for (int n : nums)
      hashmap.put(n, hashmap.getOrDefault(n, 0) + 1);

    int[] output = new int[2];
    int idx = 0;
    for (Map.Entry<Integer, Integer> item : hashmap.entrySet())
      if (item.getValue() == 1) output[idx++] = item.getKey();

    return output;
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$。
* 空间复杂度：$\mathcal{O}(N)$，哈希表所使用的空间。


####  方法二：两个掩码
本文将使用两个按位技巧：
- 使用异或运算可以帮助我们消除出现两次的数字；我们计算 `bitmask ^= x`，则 `bitmask` 留下的就是出现奇数次的位。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjYwL3hvcjMucG5n?x-oss-process=image/format,png)
- `x & (-x)` 是保留位中最右边 `1` ，且将其余的 `1` 设位 `0` 的方法。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjYwL2lzb2xhdGUzLnBuZw?x-oss-process=image/format,png)

**算法：**

首先计算 `bitmask ^= x`，则 `bitmask` 不会保留出现两次数字的值，因为相同数字的异或值为 `0`。

但是 `bitmask` 会保留只出现一次的两个数字（`x` 和 `y`）之间的差异。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjYwL2RpZmZfbmV3LnBuZw?x-oss-process=image/format,png)

我们可以直接从 `bitmask` 中提取 `x` 和 `y` 吗？不能，但是我们可以用 `bitmask` 作为标记来分离 `x` 和 `y`。

我们通过 `bitmask & (-bitmask)` 保留 `bitmask` 最右边的 `1`，这个 `1` 要么来自 `x`，要么来自 `y`。

![在这里插入图片描述](https://imgconvert.csdnimg.cn/aHR0cHM6Ly9waWMubGVldGNvZGUtY24uY29tL0ZpZ3VyZXMvMjYwL2lzb2xhdGUyX25ldy5wbmc?x-oss-process=image/format,png)
当我们找到了 `x`，那么 `y = bitmask^x`。

```python [solution2-Python]
class Solution:
    def singleNumber(self, nums: int) -> List[int]:
        # difference between two numbers (x and y) which were seen only once
        bitmask = 0
        for num in nums:
            bitmask ^= num
        
        # rightmost 1-bit diff between x and y
        diff = bitmask & (-bitmask)
        
        x = 0
        for num in nums:
            # bitmask which will contain only x
            if num & diff:
                x ^= num
        
        return [x, bitmask^x]
```

```java [solution2-Java]
class Solution {
  public int[] singleNumber(int[] nums) {
    // difference between two numbers (x and y) which were seen only once
    int bitmask = 0;
    for (int num : nums) bitmask ^= num;

    // rightmost 1-bit diff between x and y
    int diff = bitmask & (-bitmask);

    int x = 0;
    // bitmask which will contain only x
    for (int num : nums) if ((num & diff) != 0) x ^= num;

    return new int[]{x, bitmask^x};
  }
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(N)$ 的时间遍历输入数组。
* 空间复杂度：$\mathcal{O}(1)$。