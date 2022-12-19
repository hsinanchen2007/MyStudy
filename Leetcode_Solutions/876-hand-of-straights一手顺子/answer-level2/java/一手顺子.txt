#### 方法一：暴力解法【通过】

**思路**

因为手中最小的牌也一定是某个分组中的起始牌，所以反复从手中最小的牌开始组建一个长度为 `W` 的组。

**算法**

使用 `TreeMap` 或 `dict` 记录每种牌的数量 `{card: number of copies of card}`。

然后反复执行以下步骤：找到最小的一张牌（假设是 `x`），然后试图将 `x, x+1, x+2, ..., x+W-1` 这些牌的计数减 `1`。如果每次都能找到这样的组且最终手里无牌，那么分组成功，否则失败。

```java [solution1-Java]
class Solution {
    public boolean isNStraightHand(int[] hand, int W) {
        TreeMap<Integer, Integer> count = new TreeMap();
        for (int card: hand) {
            if (!count.containsKey(card))
                count.put(card, 1);
            else
                count.replace(card, count.get(card) + 1);
        }

        while (count.size() > 0) {
            int first = count.firstKey();
            for (int card = first; card < first + W; ++card) {
                if (!count.containsKey(card)) return false;
                int c = count.get(card);
                if (c == 1) count.remove(card);
                else count.replace(card, c - 1);
            }
        }

        return true;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def isNStraightHand(self, hand, W):
        count = collections.Counter(hand)
        while count:
            m = min(count)
            for k in xrange(m, m+W):
                v = count[k]
                if not v: return False
                if v == 1:
                    del count[k]
                else:
                    count[k] = v - 1

        return True
```

**复杂度分析**

* 时间复杂度：$O(N * (N/W))$，其中 $N$ 是 `hand` 的长度，$(N / W)$ 是 `min(count)` 的复杂度。在 Java 中使用 `TreeMap` 可以将 $(N / W)$ 降低到 $\log N$。

* 空间复杂度：$O(N)$。