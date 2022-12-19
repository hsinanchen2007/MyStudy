####  方法一：逐位颠倒
虽然这个问题并不难，但它常常是面试开始时的一个热身问题。重点是测试一个人对数据类型和位操作的基本知识。

在面试的时候逐位颠倒作为最直接的解决方案。

![在这里插入图片描述](https://pic.leetcode-cn.com/15bcf5b6db9b5211046655737571e3fe2668f9ecfc24ce517cd2b0882824aecd-file_1585801736085)

尽管听起来很简单，但上述逻辑的不同实现产生不同的解决方案。例如，要检索整数 `n` 中最右边的位，可以应用模运算（即 `n%2`）或与运算（即 `n &1`）。另一个例子是，为了组合反转位（例如 $2^a，2^b$）的结果，可以使用加法运算（即 $2^a+2^b$）或再次使用位或运算（即 $2^a | 2^b$）。

**算法：**
在这里，我们将展示基于上述逻辑的实现示例。

![在这里插入图片描述](https://pic.leetcode-cn.com/ca2460d77758bd033e787f6b1602f5571891520acae4eefa7bcc7f1fe48b5a2e-file_1585801736110)
关键思想是，对于位于索引 `i` 处的位，在反转之后，其位置应为 `31-i`（注：索引从零开始）。

- 我们从右到左遍历输入整数的位字符串（即 `n=n>>1`）。要检索整数的最右边的位，我们应用与运算（`n&1`）。
- 对于每个位，我们将其反转到正确的位置（即`（n&1）<<power`）。然后添加到最终结果。
- 当 `n==0` 时，我们终止迭代。

```python [solution1-Python]
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        ret, power = 0, 31
        while n:
            ret += (n & 1) << power
            n = n >> 1
            power -= 1
        return ret
```

```c++ [solution1-C++]
class Solution {
  public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t ret = 0, power = 31;
    while (n != 0) {
      ret += (n & 1) << power;
      n = n >> 1;
      power -= 1;
    }
    return ret;
  }
};
```

```go [solution1-Go]
func reverseBits(num uint32) uint32 {
    ret := uint32(0)
    power := uint32(31)
    for num != 0 {
        ret += (num & 1) << power
        num = num >> 1
        power -= 1
    }
    return ret
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(\log_2{N})$。在算法中，我们有一个循环来迭代输入的最高非零位，即$\log_2{N}$。
* 空间复杂度：$\mathcal{O}(1)$，因为不管输入是什么，内存的消耗是固定的。


####  方法二：带记忆化的按字节颠倒
有人可能会说，每字节（8 位的比特位）反转可能更有效。由于该题的输入是固定的 32 位整数，所以在本题中不一定是这样的。但是在处理长字节流时，它会变得更有效。

![在这里插入图片描述](https://pic.leetcode-cn.com/365599a4030d26a019d37ad97c201e64e2fa3ae9fd7b43d689e8a4d7f802141e-file_1585801736122)

使用字节作为迭代单位的另一个隐含优点是，我们可以使用记忆化技术，可以缓存先前计算的值，以避免重新计算。

记忆化的后续问题是：如果该函数多次被调用，你该如何优化。

若要按自己为单位反转位，可以应用上述所示的算法。在这里，我们展示一种完全基于算术和位操作，不基于任何循环语句，如下所示：

```python [example-Python]
def reverseByte(byte):
    return (byte * 0x0202020202 & 0x010884422010) % 1023
```

这个算法为用 3 个操作反转一个字节中的位，在 Sean Eron Anderson 的在线电子书 Bit Twiddling Hacks 中可以看到更多的细节。

**算法：**
- 我们按字节遍历整数。为了检索整数中最右边的字节，我们应用位掩码为 `11111111` 的与操作（即 `n&0xff`）。
- 对于每个字节，首先我们通过一个名为 `reverseByte(byte)` 的函数来反转字节中的位。然后将反转的结果添加到答案中。
- 对于函数 `reverseByte(byte)`，我们使用记忆化技术，它缓存函数的结果并直接返回结果，以便将来遇到相同的输入。

注意，可以选择更小的单位而不是字节，例如 4 位的单位，这将需要更多的计算来交换更少的缓存空间。记忆化技术是空间和计算时间之间的权衡。

```python [solution21-Python]
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        ret, power = 0, 24
        cache = dict()
        while n:
            ret += self.reverseByte(n & 0xff, cache) << power
            n = n >> 8
            power -= 8
        return ret

    def reverseByte(self, byte, cache):
        if byte not in cache:
            cache[byte] = (byte * 0x0202020202 & 0x010884422010) % 1023 
        return cache[byte]
```

```python [solution21-Python]
import functools

class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        ret, power = 0, 24
        while n:
            ret += self.reverseByte(n & 0xff) << power
            n = n >> 8
            power -= 8
        return ret

    # memoization with decorator
    @functools.lru_cache(maxsize=256)
    def reverseByte(self, byte):
        return (byte * 0x0202020202 & 0x010884422010) % 1023
```

```c++ [solution21-C++]
class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t> cache) {
        if (cache.find(byte) != cache.end()) {
            return cache[byte];
        }
        uint32_t value = (byte * 0x0202020202 & 0x010884422010) % 1023;
        cache.emplace(byte, value);
        return value;
    }

    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0, power = 24;
        map<uint32_t, uint32_t> cache;
        while (n != 0) {
            ret += reverseByte(n & 0xff, cache) << power;
            n = n >> 8;
            power -= 8;
        }
        return ret;
    }
};
```

```go [solution21-Go]
func reverseByte(b uint32, cache map[uint32]uint64) uint64 {
    value, ok := cache[b]
    if ok {
        return value
    }
    value = (uint64(b) * 0x0202020202 & 0x010884422010) % 1023
    cache[b] = value
    return value
}

func reverseBits(num uint32) uint32 {
    ret := uint64(0)
    power := uint64(24)
    var cache = map[uint32]uint64{}

    for num != 0 {
        ret += reverseByte(num & 0xff, cache) << power
        num = num >> 8
        power -= 8
    }
    return uint32(ret)
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$。尽管我们在算法中有一个循环，但是无论输入是什么，迭代次数都是固定的，因为在我们的问题中整数是固定大小（32 位）的。
* 空间复杂度：$\mathcal{O}(1)$，同样，尽管我们使用了缓存来保留反转字节的结果，但缓存中的大小总数限制为 $2^8=256$。


####  方法三：
在方法 2 中，我们展示了一个关于如何在不使用循环语句的情况下反转字节中的位的示例。在面试过程中，你可能会被要求在不使用循环的情况下反转整个 32 位。在这里，我们提出了一种只使用位操作的解决方案。

这种思想可以看作是一种分治的策略，我们通过掩码将 32 位整数划分成具有较少位的块，然后通过将美俄个块反转，最后将每个块的结果合并得到最终结果。

在下图中，我们演示如何使用上述思想反转两个位。同样的，这个想法可以应用到比特块上。

![在这里插入图片描述](https://pic.leetcode-cn.com/c57a82424197ba1f4091a67cc4a6c575b35dcc0bf9d077415838d3b22d4b1ff3-file_1585801736118)

**算法：**

我们可以通过以下步骤实现该算法：
- 首先，我们将原来的 32 位分为 2 个 16 位的块。
- 然后我们将 16 位块分成 2 个 8 位的块。
- 然后我们继续将这些块分成更小的块，直到达到 1 位的块。
- 在上述每个步骤中，我们将中间结果合并为一个整数，作为下一步的输入。

```python [solution3-Python]
class Solution:
    # @param n, an integer
    # @return an integer
    def reverseBits(self, n):
        n = (n >> 16) | (n << 16)
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8)
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4)
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2)
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1)
        return n
```

```c++ [solution3-C++]
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
        n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
        n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
        n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
        return n;
    }
};
```

```go [solution3-Go]
func reverseBits(num uint32) uint32 {
    num = (num >> 16) | (num << 16)
    num = ((num & 0xff00ff00) >> 8) | ((num & 0x00ff00ff) << 8)
    num = ((num & 0xf0f0f0f0) >> 4) | ((num & 0x0f0f0f0f) << 4)
    num = ((num & 0xcccccccc) >> 2) | ((num & 0x33333333) << 2)
    num = ((num & 0xaaaaaaaa) >> 1) | ((num & 0x55555555) << 1)
    return num
}
```

**复杂度分析**

* 时间复杂度：$\mathcal{O}(1)$，没有使用循环。
* 空间复杂度：$\mathcal{O}(1)$，没有使用变量。