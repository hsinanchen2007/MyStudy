#### 方法一： 平衡法

**思路和算法**

保证左右括号数量的 *平衡*： 计算 `'('` 出现的次数减去 `')'` 出现的次数。如果值为 `0`，那就是平衡的，如果小于 `0`，就要在前面补上缺少的 `'('`。

计算 `S` 每个前缀子数组的 *平衡度*。如果值是负数（比如说，-1），那就得在前面加上一个 `'('`。同样的，如果值是正数（比如说，`+B`），那就得在末尾处加上 `B` 个 `')'` 。

```java [solution1-Java]
class Solution {
    public int minAddToMakeValid(String S) {
        int ans = 0, bal = 0;
        for (int i = 0; i < S.length(); ++i) {
            bal += S.charAt(i) == '(' ? 1 : -1;
            // It is guaranteed bal >= -1
            if (bal == -1) {
                ans++;
                bal++;
            }
        }

        return ans + bal;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def minAddToMakeValid(self, S):
        ans = bal = 0
        for symbol in S:
            bal += 1 if symbol == '(' else -1
            # It is guaranteed bal >= -1
            if bal == -1:
                ans += 1
                bal += 1
        return ans + bal
```

**复杂度分析**

* 时间复杂度： $O(N)$，其中 $N$ 是 `S` 的长度。

* 空间复杂度： $O(1)$。