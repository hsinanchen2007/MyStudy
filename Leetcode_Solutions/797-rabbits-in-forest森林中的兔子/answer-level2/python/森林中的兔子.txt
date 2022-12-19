#### 方法一：计数【通过】

**思路**

一个兔子只会说跟它颜色相同的兔子还有多少个，说不同数字的兔子之间颜色一定不同。因此可以分别对不同颜色的兔子进行计数。

现在有 `13` 个兔子回答 `5`。假设其中有一只红色的兔子，在回答 `5` 的兔子之中还可以有五只红兔子。再假设其中还有一只蓝色的兔子，同样的道理还可以有五只蓝兔子。这时候总共就有 `12` 只兔子了，`6` 只红色，`6` 只蓝色。但回答 `5` 的还有一只额外的兔子，这只兔子只能是其他的颜色了，同时因为这只兔子回答的是 `5`，也一定还有同颜色的其他五只兔子。因此这种情况下森林中最少有 `18` 只兔子。

**算法**

假设回答 `k` 的兔子的数量为 `v = count[k]`，通过上面分析可以知道至少有 `a` 只兔子，其中 `a` 是满足 `a >= count[k]` 的最小 `k + 1` 的倍数。

```java [solution1-Java]
class Solution {
    public int numRabbits(int[] answers) {
        int[] count = new int[1000];
        for (int x: answers) count[x]++;

        int ans = 0;
        for (int k = 0; k < 1000; ++k)
            ans += Math.floorMod(-count[k], k+1) + count[k];
        return ans;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def numRabbits(self, answers):
        count = collections.Counter(answers)
        return sum(-v % (k+1) + v for k, v in count.iteritems())
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 为兔子的数量。
* 空间复杂度：$O(N)$。