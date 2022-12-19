#### 方法一： 根据出现次数排序 【通过】

**思路**

如果要让 `'a'` 不连续，很自然可以写出 `"aXaXaXa..."` 这种形式，其中 `"X"` 是除了 `'a'` 之外的字符。现在假设有一种排列方式可以使得任意两相邻字符不同，我们来找出这种排列方式。

首先将 `S` 进行排序，排序之后所有相同的字符都连续出现了。接着以间隔的方式重新排布，如 `S[3], S[0], S[4], S[1], S[5], S[2]`，让相同的字符互相不相邻。（这里是从下标 1 开始，每次间隔 2 来输出）

在 `N` 为偶数，下标 `0` 或 `1` 处有重复三次字符的情况下，像 `S[2], S[0], S[3], S[1], S[4]` 这样间隔输出是可能得不到想要的结果的。在这种情况下为了防止错误的输出，我们需要确保出现次数最多的字符要出现在重排数组的最后位置。

上述我们讨论的是在有这种排列的情况下如何找到，那自然也是有可能不存在这种排列的。在字符串长度为 `N` 的情况下，如果有一个字母出现的次数超过 `(N+1) / 2`，这时候就不存在这样一种排列。

**算法**

首先找出所有字符出现的次数，根据字符出现的次数来排序整个字符串。如果一个字符出现的次数超过了 `(N + 1) / 2`，那么就不存在这样一种排列。否则，按顺序间隔输出字符就可以得到满足要求的排列。

```python [solution1-Python]
class Solution(object):
    def reorganizeString(self, S):
        N = len(S)
        A = []
        for c, x in sorted((S.count(x), x) for x in set(S)):
            if c > (N+1)/2: return ""
            A.extend(c * x)
        ans = [None] * N
        ans[::2], ans[1::2] = A[N/2:], A[:N/2]
        return "".join(ans)
```

```java [solution1-Java]
class Solution {
    public String reorganizeString(String S) {
        int N = S.length();
        int[] counts = new int[26];
        for (char c: S.toCharArray()) counts[c-'a'] += 100;
        for (int i = 0; i < 26; ++i) counts[i] += i;
        //Encoded counts[i] = 100*(actual count) + (i)
        Arrays.sort(counts);

        char[] ans = new char[N];
        int t = 1;
        for (int code: counts) {
            int ct = code / 100;
            char ch = (char) ('a' + (code % 100));
            if (ct > (N+1) / 2) return "";
            for (int i = 0; i < ct; ++i) {
                if (t >= N) t = 0;
                ans[t] = ch;
                t += 2;
            }
        }

        return String.valueOf(ans);
    }
}
```


**复杂度分析**

* 时间复杂度: $O(A(N + \log{A}))$，其中 $N$ 是 $S$ 的长度，$A$ 是字母表的大小。在 Java 的实现中复杂度为 $O(N + A \log {A})$。如果 A 是固定的，复杂度就是 $O(N)$。

* 空间复杂度: $O(N)$。 在 Java 的实现中复杂度为 $O(N + \mathcal{A})$。


#### 方法二： 贪心堆 【通过】

**思路**

方法一的延伸解法，利用了贪心的思想，每次输出剩余出现次数最多的字符就可以了。

可以这么做的原因在于，只有当一个字符出现的次数超过 `(N+1) / 2` 的情况下，这个问题才无解。只要初试情况下这个条件满足，每次都输出剩余出现次数最多的字符就可以将这个条件一直保持下去。
堆是一种天然能返回当前剩余出现次数最大字符的数据结构。

**算法**

在堆中存储 `(count, letter)` 这种格式的元素（在 Python 的实现中存储的是 count 的负数形式）。
每次从堆中弹出两个元素出来（代表两个剩余次数最大和第二大的字符），接着将这两个字符中与之前输出字符不同，出现次数最大的字符输出。之后把重新计算的剩余次数和字符再压入栈中。
最后，堆中可能会剩下一个元素，这个元素出现次数一定是 `1`。如果不是的话，那就不可能有这种排列。

**对条件不变性的证明**

前面提到了条件不变性，但没有证明为什么是正确的。定义 $C_i$ 为每个字母已经被输出的次数，$N$ 为还没有输出的字母的数量。接下来会展示这个过程中为什么 $2 * \max\limits_i(C_i) \leq N+1$ 是能一直保持的。

设 $C'_i$ 为一次输出之后 $C_i$ 的新值。

* 如果 $\max(C_i) > 3rdmax(C_i)$， 那么 $\max(C'_i) \leq \max(C_i) - 1$, 可以推出 $2\max(C'_i) \leq 2\max(C_i) - 2 \leq N-1$。

* 如果 $M = \max(C_i) = 3rdmax(C_i)$，那么 $3M \leq N$。同时，由于 $M \geq 1$， $N \geq 3$。那么可以得到 $2M \leq \frac{2N}{3} \leq N-1$。

以上就完成了对条件不变性的证明。

```python [solution2-Python]
class Solution(object):
    def reorganizeString(self, S):
        pq = [(-S.count(x), x) for x in set(S)]
        heapq.heapify(pq)
        if any(-nc > (len(S) + 1) / 2 for nc, x in pq):
            return ""

        ans = []
        while len(pq) >= 2:
            nct1, ch1 = heapq.heappop(pq)
            nct2, ch2 = heapq.heappop(pq)
            #This code turns out to be superfluous, but explains what is happening
            #if not ans or ch1 != ans[-1]:
            #    ans.extend([ch1, ch2])
            #else:
            #    ans.extend([ch2, ch1])
            ans.extend([ch1, ch2])
            if nct1 + 1: heapq.heappush(pq, (nct1 + 1, ch1))
            if nct2 + 1: heapq.heappush(pq, (nct2 + 1, ch2))

        return "".join(ans) + (pq[0][1] if pq else '')
```

```java [solution2-Java]
class Solution {
    public String reorganizeString(String S) {
        int N = S.length();
        int[] count = new int[26];
        for (char c: S.toCharArray()) count[c-'a']++;
        PriorityQueue<MultiChar> pq = new PriorityQueue<MultiChar>((a, b) ->
            a.count == b.count ? a.letter - b.letter : b.count - a.count);

        for (int i = 0; i < 26; ++i) if (count[i] > 0) {
            if (count[i] > (N + 1) / 2) return "";
            pq.add(new MultiChar(count[i], (char) ('a' + i)));
        }

        StringBuilder ans = new StringBuilder();
        while (pq.size() >= 2) {
            MultiChar mc1 = pq.poll();
            MultiChar mc2 = pq.poll();
            /*This code turns out to be superfluous, but explains what is happening
            if (ans.length() == 0 || mc1.letter != ans.charAt(ans.length() - 1)) {
                ans.append(mc1.letter);
                ans.append(mc2.letter);
            } else {
                ans.append(mc2.letter);
                ans.append(mc1.letter);
            }*/
            ans.append(mc1.letter);
            ans.append(mc2.letter);
            if (--mc1.count > 0) pq.add(mc1);
            if (--mc2.count > 0) pq.add(mc2);
            }
        }

        if (pq.size() > 0) ans.append(pq.poll().letter);
        return ans.toString();
    }
}
class MultiChar {
    int count;
    char letter;
    MultiChar(int ct, char ch) {
        count = ct;
        letter = ch;
    }
}
```


**复杂度分析**

* 时间复杂度: $O(N \log{A}))$，其中 $N$ 为 $S$ 的长度，$A$ 为字母表的大小。如果 $A$ 是一个定值，那么复杂度为 $O(N)$。

* 空间复杂度: $O(A)$。如果 $A$ 是一个定值，那么复杂度为 $O(1)$。