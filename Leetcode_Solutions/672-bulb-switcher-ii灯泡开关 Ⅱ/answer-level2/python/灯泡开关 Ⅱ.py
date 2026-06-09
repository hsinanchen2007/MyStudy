##  解决方法：
####  方法一：减少搜索空间 [通过]
由于搜索空间非常大（$2^N$ 个灯光的状态，$4^M$ 个操作顺序 ），让我们尝试减少它。 

前6个灯唯一地决定了其余的灯。这是因为每一个修改  第 $x$  的灯光的操作都会修改第 $(x+6)$ 的灯光。

另外：进行 A 操作后接 B 操作 和 B 操作后接 A 操作是一样的，所以我们可以假设我们按顺序进行所有操作。  

最后，连续两次执行相同的操作与不执行任何操作相同。所以我们只需要考虑每个操作是 0 次还是 1 次。 

**算法：**
- 假设我们做了第 $i$ 个操作 $f_i$ 次。 也就是说：$c_i = f_i$ ($\mod 2$ )
- 因为 $c_i \equiv f_i$ and $c_i \leq f_i$，所以 $\sum f_i \not \equiv \sum c_i$ 和 $\sum f_i<\sum c_i$ 是不可能的。否则，可以通过一个简单的构造来实现：执行由 $c_i$ 指定的操作，然后使用剩余的偶数操作执行操作 1。 
- 对于每个可能性，让我们模拟并记住前 6 个灯的状态，将其存储在集合结构 `seen` 中。最后，我们将返回这个集合的大小。 

```Python [ ]
def flipLights(self, n, m):
    seen = set()
    for cand in itertools.product((0, 1), repeat = 4):
        if sum(cand) % 2 == m % 2 and sum(cand) <= m:
            A = []
            for i in xrange(min(n, 3)):
                light = 1
                light ^= cand[0]
                light ^= cand[1] and i % 2
                light ^= cand[2] and i % 2 == 0
                light ^= cand[3] and i % 3 == 0
                A.append(light)
            seen.add(tuple(A))

    return len(seen)
```

```Java [ ]
class Solution {
    public int flipLights(int n, int m) {
        Set<Integer> seen = new HashSet();
        n = Math.min(n, 6);
        int shift = Math.max(0, 6-n);
        for (int cand = 0; cand < 16; ++cand) {
            int bcount = Integer.bitCount(cand);
            if (bcount % 2 == m % 2 && bcount <= m) {
                int lights = 0;
                if (((cand >> 0) & 1) > 0) lights ^= 0b111111 >> shift;
                if (((cand >> 1) & 1) > 0) lights ^= 0b010101 >> shift;
                if (((cand >> 2) & 1) > 0) lights ^= 0b101010 >> shift;
                if (((cand >> 3) & 1) > 0) lights ^= 0b100100 >> shift;
                seen.add(lights);
            }
        }
        return seen.size();
    }
}
```


**复杂度分析**

* 时间复杂度：$O(1)$。
* 空间复杂度：$O(1)$。


####  方法二：
**算法：**
- 因为前 6 个灯唯一地决定了其余的灯。这是因为修改第 $x$ 灯光的每个操作都会修改 第 $(x+6)$ 灯光，因此 $x$ 灯光始终等于 $(x+6)$ 灯光。 
- 实际上，前 3 个灯唯一地确定了序列的其余部分，如下表所示，用于执行操作 a, b, c, d:

```
Light 1 = 1 + a + c + d
Light 2 = 1 + a + b
Light 3 = 1 + a + c
Light 4 = 1 + a + b + d
Light 5 = 1 + a + c
Light 6 = 1 + a + b
```

- 上述理由表明，在不损失一般性的情况下，取 $n = min(n, 3)$  是合理的。
- 让我们用 $(a, b, c)$ 来表示灯的状态。与值为 $(1, 1, 1), (0, 1, 0), (1, 0, 1),$  $(1, 0, 0)$ xor. 
- 当 $m=0$ 时，所有灯都亮起，只有一个状态 $(1, 1, 1)$。在这种情况下，答案总是 1。 
- 当 $m=1$ 时，我们可以得到状态 $(0, 0, 0)$, $(1, 0, 1)$, $(0, 1, 0)$,  $(0, 1, 1)$。在这种情况下，对于 $n = 1, 2, 3$ 的答案是 $2, 3, 4$。 
- 当 $m=2$ 时，我们可以检查是否可以获得 7 个状态：除$(0, 1, 1)$之外的所有状态。在这种情况下，$n = 1, 2, 3$ 的答案是 $2, 4, 7$。 
- 当 $m=3$ 时，我们可以得到所有 8 个状态。在这种情况下，$n = 1, 2, 3$ 的答案是 $2, 4, 8$

```Python [ ]
class Solution(object):
    def flipLights(self, n, m):
        n = min(n, 3)
        if m == 0: return 1
        if m == 1: return [2, 3, 4][n-1]
        if m == 2: return [2, 4, 7][n-1]
        return [2, 4, 8][n-1]
```

```Java [ ]
class Solution {
    public int flipLights(int n, int m) {
        n = Math.min(n, 3);
        if (m == 0) return 1;
        if (m == 1) return n == 1 ? 2 : n == 2 ? 3 : 4;
        if (m == 2) return n == 1 ? 2 : n == 2 ? 4 : 7;
        return n == 1 ? 2 : n == 2 ? 4 : 8;
    }
}
```

**复杂度分析**
- 时空复杂性：$O(1)$。整个程序使用常量。