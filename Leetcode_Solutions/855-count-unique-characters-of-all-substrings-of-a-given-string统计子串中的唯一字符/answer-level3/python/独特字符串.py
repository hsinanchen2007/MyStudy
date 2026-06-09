#### 方法一：递推

**分析**

我们用 $U(S)$ 表示字符串 `S` 中独特字符的个数，例如 $U(\text{"LETTER"}) = 2$。在计算 $U(S)$ 时，我们可以对字母表中的每个字符，分别判断它是否只在 `S` 中出现一次。我们用 $U_{"A"}(S)$ 表示 $A$ 是否为 `S` 中的独特字符，如果是，那么它的值为 `1`；如果不是，那么它的值为 `0`。那么我们有 $U(S) = \sum_{c \in \mathcal{A}} U_c(S)$，其中 $\mathcal{A} = \{ \text{"A"}, \text{"B"}, \dots \}$ 为字母表。

将 $U(S)$ 分解为若干个 $U_c(S)$ 的和之后，问题就变得简单很多了。我们只需要考虑这样一个问题：对于一个字符（例如 `"A"`），`x` 中有多少个子串只包含一个 `"A"`？举一个例子，如果我们知道 `S` 中的某些位置 `S[10], S[14], S[20]` 的字符为 `"A"`，其余位置的字符均不为 `"A"`，那么我们就可以计算出，以 `S[8]` 开始且只包含一个 `"A"` 的子串有 `4` 个，它们分别以 `S[10], S[11], S[12], S[13]` 结尾；以 `S[12]` 开始且只包含一个 `"A"` 的子串有 `6` 个，它们分别以 `S[14], S[15], S[16], S[17], S[18], S[19]` 结尾，以此类推。对于一个开始位置 `S[i]`，我们对字母表中的每个字符，都计算出只包含一个该字符的子串的数量，再进行累加，就可以得到所有以 `S[i]` 开始的子串的 $U(S)$ 值之和。再对所有的 $U(S)$ 进行累加，就可以得到最终的答案。

我们用 $F(i)$ 表示开始位置为 `S[i]` 的子串的 $U(S)$ 值之和。在初始 `i = 0` 时，$F(0)$ 为 $\sum_{c \in \mathcal{A}} \text{index}[c][1] - \text{index}[c][0]$，其中 `index[c]` 是一个列表，它按照递增的顺序存储了 `S` 中出现字符 `c` 的位置，例如在上面一个例子中，`index["A"] = [10, 14, 20]`。

接下来，我们观察 $F(1)$ 相对于 $F(0)$ 的变化是哪些项，希望用 $F(0)$ 的值递推出 $F(1)$ 的值。假设 `S[0]` 的字符为 `"B"`，那么对于所有的 $c \neq \text{"B"}$，$\text{index}[c][1] - \text{index}[c][0]$ 的值都没有发生变化，只有 $c = \text{"B"}$ 的那一项从 $\text{index}[\text{"B"}][1] - \text{index}[\text{"B"}][0]$ 变成了 $\text{index}[\text{"B"}][2] - \text{index}[\text{"B"}][1]$。以此类推，当我们从 $F(i)$ 递推到 $F(i + 1)$ 时，只需要变化 $c = S[i]$ 的那一项即可。

```Java [sol1]
class Solution {
    Map<Character, List<Integer>> index;
    int[] peek;
    int N;

    public int uniqueLetterString(String S) {
        index = new HashMap();
        peek = new int[26];
        N = S.length();

        for (int i = 0; i < S.length(); ++i) {
            char c = S.charAt(i);
            index.computeIfAbsent(c, x-> new ArrayList<Integer>()).add(i);
        }

        long cur = 0, ans = 0;
        for (char c: index.keySet()) {
            index.get(c).add(N);
            index.get(c).add(N);
            cur += get(c);
        }

        for (char c: S.toCharArray()) {
            ans += cur;
            long oldv = get(c);
            peek[c - 'A']++;
            cur += get(c) - oldv;
        }
        return (int) ans % 1_000_000_007;
    }

    public long get(char c) {
        List<Integer> indexes = index.get(c);
        int i = peek[c - 'A'];
        return indexes.get(i+1) - indexes.get(i);
    }
}
```

```Python [sol1]
class Solution(object):
    def uniqueLetterString(self, S):
        N = len(S)
        index = collections.defaultdict(list)
        peek = collections.defaultdict(int)
        for i, c in enumerate(S):
            index[c].append(i)
        for c in index:
            index[c].extend([N, N])

        def get(c):
            return index[c][peek[c] + 1] - index[c][peek[c]]

        ans = 0
        cur = sum(get(c) for c in index)
        for i, c in enumerate(S):
            ans += cur
            oldv = get(c)
            peek[c] += 1
            cur += get(c) - oldv
        return ans % (10**9 + 7)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(N)$。

#### 方法二：对于每个字母分别计数

我们可以在方法一上进行改进，在不改变时间复杂度的情况下，让代码变得更加简洁。

我们直接对于每个字符 `c`，计算出仅包含 `c` 一次的子串个数。使用和方法一相同的例子，考虑字母 `"A"`，并且有 `S[10] = S[14] = S[20] = "A"`，我们可以计算出仅包含 `S[14]` 的子串个数为 `4 * 6 = 24`，其中 `4` 表示子串的开始位置可以选择 `11, 12, 13, 14`，`6` 表示子串的结束位置可以选择 `14, 15, 16, 17, 18, 19`，根据乘法原理，子串的个数为 `24`。我们对于字母 `"A"` 出现的其它位置（例如 `S[10]` 和 `S[20]`）分别进行同样的计数，并且需要考虑边界情况，就可以得到仅包含字母 `"A"` 一次的子串个数。

最后对于每个字符 `c`，将计数结果进行累加，就得到了最终的答案。

```Java [sol2]
class Solution {
    public int uniqueLetterString(String S) {
        Map<Character, List<Integer>> index = new HashMap();
        for (int i = 0; i < S.length(); ++i) {
            char c = S.charAt(i);
            index.computeIfAbsent(c, x-> new ArrayList<Integer>()).add(i);
        }

        long ans = 0;
        for (List<Integer> A: index.values()) {
            for (int i = 0; i < A.size(); ++i) {
                long prev = i > 0 ? A.get(i-1) : -1;
                long next = i < A.size() - 1 ? A.get(i+1) : S.length();
                ans += (A.get(i) - prev) * (next - A.get(i));
            }
        }

        return (int) ans % 1_000_000_007;
    }
}
```

```Python [sol2]
class Solution(object):
    def uniqueLetterString(self, S):
        index = collections.defaultdict(list)
        for i, c in enumerate(S):
            index[c].append(i)

        ans = 0
        for A in index.values():
            A = [-1] + A + [len(S)]
            for i in xrange(1, len(A) - 1):
                ans += (A[i] - A[i-1]) * (A[i+1] - A[i])
        return ans % (10**9 + 7)
```

**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：$O(N)$，可以优化到 $O(\mathcal{A})$。