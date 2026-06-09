#### 方法一：逆推

**分析**

如果我们正着考虑戳印序列，即将问号序列变为目标序列 `target`，那么这个问题会很难下手，因为某一个戳印会将前面的戳印覆盖掉。但我们如果倒着考虑这个问题（逆推），即将目标序列 `target` 变为问号序列，那么这个问题就变得可解决了。

我们将 `target` 中从第 `i` 个字符开始的长度为 `stamp.length` 的字符串称为第 `i` 个窗口。在第一步时，只有和 `stamp` 完全匹配的窗口才能进行戳印，而被戳印的所有位置都会变成问号 `?`，在后续的戳印过程中，问号可以匹配任意字符。

例如 `target` 为 `"aabcaca"` 且 `stamp` 为 `"abca"`，在逆推时，首先选择第 `1` 个窗口戳印，`target` 变为 `"a????ca"`，随后选择第 `3`，`0` 个窗口戳印，`target` 依次变为 `"a??????"`，`"???????"`。

**算法**

我们对每个窗口维护两个集合 `made` 和 `todo`，前者表示和 `stamp` 可以匹配的位置，后者表示不可以匹配的位置（后者中只有某个位置的字符变成了问号，它才会变成可以匹配的位置）。只有当一个窗口的 `todo` 集合为空，这个窗口才可以被戳印，从而把一些字符变成问号。

我们用一个队列存储所有因为戳印而变成问号的字符位置。队列初始时包含所有 `todo` 集合一开始就为空的窗口对应的位置。当我们取出队列中的一个位置时，我们遍历所有覆盖了该位置的窗口，并且更新这些窗口的 `todo` 集合。如果 `todo` 集合变为空，那就说明产生了一个新的可被戳印的窗口，我们把这个窗口中所有未变成问号的字符的位置添加入队列中。

```Java [sol1]
class Solution {
    public int[] movesToStamp(String stamp, String target) {
        int M = stamp.length(), N = target.length();
        Queue<Integer> queue = new ArrayDeque();
        boolean[] done = new boolean[N];
        Stack<Integer> ans = new Stack();
        List<Node> A = new ArrayList();

        for (int i = 0; i <= N-M; ++i) {
            // For each window [i, i+M), A[i] will contain
            // info on what needs to change before we can
            // reverse stamp at this window.

            Set<Integer> made = new HashSet();
            Set<Integer> todo = new HashSet();
            for (int j = 0; j < M; ++j) {
                if (target.charAt(i+j) == stamp.charAt(j))
                    made.add(i+j);
                else
                    todo.add(i+j);
            }

            A.add(new Node(made, todo));

            // If we can reverse stamp at i immediately,
            // enqueue letters from this window.
            if (todo.isEmpty()) {
                ans.push(i);
                for (int j = i; j < i + M; ++j) if (!done[j]) {
                    queue.add(j);
                    done[j] = true;
                }
            }
        }

        // For each enqueued letter (position),
        while (!queue.isEmpty()) {
            int i = queue.poll();

            // For each window that is potentially affected,
            // j: start of window
            for (int j = Math.max(0, i-M+1); j <= Math.min(N-M, i); ++j) {
                if (A.get(j).todo.contains(i)) {  // This window is affected
                    A.get(j).todo.remove(i);
                    if (A.get(j).todo.isEmpty()) {
                        ans.push(j);
                        for (int m: A.get(j).made) if (!done[m]) {
                            queue.add(m);
                            done[m] = true;
                        }
                    }
                }
            }
        }

        for (boolean b: done)
            if (!b) return new int[0];

        int[] ret = new int[ans.size()];
        int t = 0;
        while (!ans.isEmpty())
            ret[t++] = ans.pop();

        return ret;
    }
}

class Node {
    Set<Integer> made, todo;
    Node(Set<Integer> m, Set<Integer> t) {
        made = m;
        todo = t;
    }
}
```

```Python [sol1]
class Solution(object):
    def movesToStamp(self, stamp, target):
        M, N = len(stamp), len(target)

        queue = collections.deque()
        done = [False] * N
        ans = []
        A = []
        for i in xrange(N - M + 1):
            # For each window [i, i+M),
            # A[i] will contain info on what needs to change
            # before we can reverse stamp at i.

            made, todo = set(), set()
            for j, c in enumerate(stamp):
                a = target[i+j]
                if a == c:
                    made.add(i+j)
                else:
                    todo.add(i+j)
            A.append((made, todo))

            # If we can reverse stamp at i immediately,
            # enqueue letters from this window.
            if not todo:
                ans.append(i)
                for j in xrange(i, i + len(stamp)):
                    if not done[j]:
                        queue.append(j)
                        done[j] = True

        # For each enqueued letter,
        while queue:
            i = queue.popleft()

            # For each window that is potentially affected,
            # j: start of window
            for j in xrange(max(0, i-M+1), min(N-M, i)+1):
                if i in A[j][1]:  # This window is affected
                    A[j][1].discard(i) # Remove it from todo list of this window
                    if not A[j][1]:  # Todo list of this window is empty
                        ans.append(j)
                        for m in A[j][0]: # For each letter to potentially enqueue,
                            if not done[m]:
                                queue.append(m)
                                done[m] = True

        return ans[::-1] if all(done) else []
```

**复杂度分析**

* 时间复杂度：$O(N(N-M))$，其中 $M$ 和 $N$ 分别是数组 `stamp` 和 `target` 的长度。

* 空间复杂度：$O(N(N-M))$。