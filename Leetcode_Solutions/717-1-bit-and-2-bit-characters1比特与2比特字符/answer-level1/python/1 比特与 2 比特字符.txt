#### 方法一：线性扫描

我们可以对 $\mathrm{bits}$ 数组从左到右扫描来判断最后一位是否为一比特字符。当扫描到第 $i$ 位时，如果 $\mathrm{bits}[i]=1$，那么说明这是一个两比特字符，将 $i$ 的值增加 2。如果 $\mathrm{bits}[i]=0$，那么说明这是一个一比特字符，将 $i$ 的值增加 1。

如果 $i$ 最终落在了 $\mathrm{bits}.\mathrm{length}-1$ 的位置，那么说明最后一位一定是一比特字符。

```Python [sol1]
class Solution(object):
    def isOneBitCharacter(self, bits):
        i = 0
        while i < len(bits) - 1:
            i += bits[i] + 1
        return i == len(bits) - 1
```

```Java [sol1]
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = 0;
        while (i < bits.length - 1) {
            i += bits[i] + 1;
        }
        return i == bits.length - 1;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $n$ 是 $\mathrm{bits}$ 数组的长度。
* 空间复杂度：$O(1)$。

#### 方法二：贪心

三种字符分别为 `0`，`10` 和 `11`，那么 $\mathrm{bits}$ 数组中出现的所有 0 都表示一个字符的结束位置（无论其为一比特还是两比特）。因此最后一位是否为一比特字符，只和他左侧出现的连续的 1 的个数（即它与倒数第二个 0 出现的位置之间的 1 的个数，如果 $\mathrm{bits}$ 数组中只有 1 个 0，那么就是整个数组的长度减一）有关。如果 1 的个数为偶数个，那么最后一位是一比特字符，如果 1 的个数为奇数个，那么最后一位不是一比特字符。

```Python [sol2]
class Solution(object):
    def isOneBitCharacter(self, bits):
        parity = bits.pop()
        while bits and bits.pop(): parity ^= 1
        return parity == 0
```

```Java [sol2]
class Solution {
    public boolean isOneBitCharacter(int[] bits) {
        int i = bits.length - 2;
        while (i >= 0 && bits[i] > 0) i--;
        return (bits.length - i) % 2 == 0;
    }
}
```

**复杂度分析**

* 时间复杂度：$O(n)$，其中 $N$ 是 $\mathrm{bits}$ 数组的长度。
* 空间复杂度：$O(1)$。