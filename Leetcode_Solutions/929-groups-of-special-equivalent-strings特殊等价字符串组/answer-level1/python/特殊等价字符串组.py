#### 方法：计数

**思路和算法**

让我们试着表述一个特殊等价的字符串 $S$，通过找到函数 $\mathcal{C}$ 使得 $S \equiv T \iff \mathcal{C}(S) = \mathcal{C}(T)$。

通过交换，我们可以排列偶数索引字母和奇数索引字母。这些排列的特征在于字母的数量：所有这样的排列都有相同的数量，不同的数量会产生不同的排列。

因此，函数 $\mathcal{C}(S) =$（S 中偶数索引字母的数量，其后是 S 中奇数索引字母的数量）成功地刻画了这一等价关系。

然后，我们统计出满足 $S \in A$ 的 $\mathcal{C}(S)$ 的数量。

```java [mfQicAZA-Java]
class Solution {
    public int numSpecialEquivGroups(String[] A) {
        Set<String> seen = new HashSet();
        for (String S: A) {
            int[] count = new int[52];
            for (int i = 0; i < S.length(); ++i)
                count[S.charAt(i) - 'a' + 26 * (i % 2)]++;
            seen.add(Arrays.toString(count));
        }
        return seen.size();
    }
}
```
```python [mfQicAZA-Python]
class Solution(object):
    def numSpecialEquivGroups(self, A):
        def count(A):
            ans = [0] * 52
            for i, letter in enumerate(A):
                ans[ord(letter) - ord('a') + 26 * (i%2)] += 1
            return tuple(ans)

        return len({count(word) for word in A})
```


**复杂度分析**

* 时间复杂度：$O(\sum\limits_{i} (A_i)\text{.length})$。

* 空间复杂度：$O(N)$，其中 $N$ 是 `A` 的长度。