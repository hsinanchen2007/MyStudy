#### 方法：情况列举

**思路**

如果 `A[i] == B[i]`，我们就说 `i` 是*匹配的*，否则称 `i` 是*不匹配的*。亲密字符串几乎是完全匹配的，因为一次交换只会影响到两个索引。

如果交换 `A[i]` 和 `A[j]` 可以证明 `A` 和 `B` 是亲密字符串，那么就有 `A[i] == B[j]` 以及 `A[j] == B[i]`。 这意味着在 `A[i], A[j], B[i], B[j]` 这四个自由变量中，只存在两种情况：`A[i] == A[j]` 或 `A[i] != A[j]` 

**算法**

让我们来看看这些情况。

在 `A[i] == A[j] == B[i] == B[j]` 的情况下，字符串 `A` 与 `B` 相等。因此，如果 `A == B`，我们应当检查每个索引 `i` 以寻找具有相同值的两个匹配。

在 `A[i] == B[j], A[j] == B[i], (A[i] != A[j])` 的情况下，其余索引是相匹配的。所以如果 `A` 和 `B` 只有两个不匹配的索引（记作 `i` 和 `j`），我们应该检查并确保等式 `A[i] == B[j]` 和 `A[j] == B[i]` 成立。

```java [uHQZQkE8-Java]
class Solution {
    public boolean buddyStrings(String A, String B) {
        if (A.length() != B.length()) return false;
        if (A.equals(B)) {
            int[] count = new int[26];
            for (int i = 0; i < A.length(); ++i)
                count[A.charAt(i) - 'a']++;

            for (int c: count)
                if (c > 1) return true;
            return false;
        } else {
            int first = -1, second = -1;
            for (int i = 0; i < A.length(); ++i) {
                if (A.charAt(i) != B.charAt(i)) {
                    if (first == -1)
                        first = i;
                    else if (second == -1)
                        second = i;
                    else
                        return false;
                }
            }

            return (second != -1 && A.charAt(first) == B.charAt(second) &&
                    A.charAt(second) == B.charAt(first));
        }
    }
}
```
```python [uHQZQkE8-Python]
class Solution(object):
    def buddyStrings(self, A, B):
        if len(A) != len(B): return False
        if A == B:
            seen = set()
            for a in A:
                if a in seen:
                    return True
                seen.add(a)
            return False
        else:
            pairs = []
            for a, b in itertools.izip(A, B):
                if a != b:
                    pairs.append((a, b))
                if len(pairs) >= 3: return False
            return len(pairs) == 2 and pairs[0] == pairs[1][::-1]
```


**复杂度分析**

* 时间复杂度：$O(N)$，其中 $N$ 是 `A` 和 `B` 的长度。

* 空间复杂度：$O(1)$。