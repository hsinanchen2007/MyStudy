#### 方法：回溯

**思路和算法**

只有 4 张牌，且只能执行 4 种操作。即使所有运算符都不进行交换，最多也只有 $12 * 6 * 2 * 4 * 4 * 4 = 9216$ 种可能性，这使得我们可以尝试所有这些可能。

具体来说，我们有 12 种方式先选出两个数字（有序），并执行 4 种操作之一（12 * 4）。然后，剩下 3 个数字，我们从中选择 2 个并执行 4 种操作之一（6 * 4）。

最后我们剩下两个数字，并在 2 * 4 种可能之中作出最终选择。

我们将对我们的数字或结果数字执行 3 次二元运算（`+`，`-`，`*`，`/` 是运算）。因为 `-` 和 `/` 不满足交换律，我们必须仔细考虑 `a / b` 和 `b / a`。

对于在我们的列表中移除 `a, b` 这两个数字的每一种方法，以及它们可能产生的每种结果，如 `a + b`、`a / b`等，我们将采用递归的方法解决这个较小的数字列表上的问题。

```java [nPf39raY-Java]
class Solution {
    public boolean judgePoint24(int[] nums) {
        ArrayList A = new ArrayList<Double>();
        for (int v: nums) A.add((double) v);
        return solve(A);
    }
    private boolean solve(ArrayList<Double> nums) {
        if (nums.size() == 0) return false;
        if (nums.size() == 1) return Math.abs(nums.get(0) - 24) < 1e-6;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i != j) {
                    ArrayList<Double> nums2 = new ArrayList<Double>();
                    for (int k = 0; k < nums.size(); k++) if (k != i && k != j) {
                        nums2.add(nums.get(k));
                    }
                    for (int k = 0; k < 4; k++) {
                        if (k < 2 && j > i) continue;
                        if (k == 0) nums2.add(nums.get(i) + nums.get(j));
                        if (k == 1) nums2.add(nums.get(i) * nums.get(j));
                        if (k == 2) nums2.add(nums.get(i) - nums.get(j));
                        if (k == 3) {
                            if (nums.get(j) != 0) {
                                nums2.add(nums.get(i) / nums.get(j));
                            } else {
                                continue;
                            }
                        }
                        if (solve(nums2)) return true;
                        nums2.remove(nums2.size() - 1);
                    }
                }
            }
        }
        return false;
    }
}
```
```python [nPf39raY-Python]
from operator import truediv, mul, add, sub

class Solution(object):
    def judgePoint24(self, A):
        if not A: return False
        if len(A) == 1: return abs(A[0] - 24) < 1e-6

        for i in xrange(len(A)):
            for j in xrange(len(A)):
                if i != j:
                    B = [A[k] for k in xrange(len(A)) if i != k != j]
                    for op in (truediv, mul, add, sub):
                        if (op is add or op is mul) and j > i: continue
                        if op is not truediv or A[j]:
                            B.append(op(A[i], A[j]))
                            if self.judgePoint24(B): return True
                            B.pop()
        return False
```



**复杂度分析**

* 时间复杂度：$O(1)$，总计 9216 种可能的硬性限制，对于每种可能，我们执行操作的复杂度为 $O(1)$。

* 空间复杂度：$O(1)$，我们的中间数组最多有 4 个元素，所生成的数字由复杂度 $O(1)$ 的因子限定。