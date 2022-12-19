#### 方法一：数学

当 `K = 1` 时，每次操作只能将第一个字符移动到末尾，因此字符串 `S` 可以看成一个头尾相连的环。如果 `S` 的长度为 $N$，我们只需要找出这 $N$ 个位置中字典序最小的字符串即可。

当 `K = 2` 时，可以发现，我们能够交换字符串中任意两个相邻的字母。具体地，设字符串 `S` 为 `S[1], S[2], ..., S[i], S[i + 1], ..., S[N]`，我们需要交换 `S[i]` 和 `S[j]`。首先我们依次将 `S[i]` 之前的所有字符依次移到末尾，得到

`S[i], S[i + 1], ..., S[N], S[1], S[2], ..., S[i - 1]`

随后我们先将 `S[i + 1]` 移到末尾，再将 `S[i]` 移到末尾，得到

`S[i + 2], ..., S[N], S[1], S[2], ..., S[i - 1], S[i + 1], S[i]`

最后将 `S[i + 1]` 之后的所有字符依次移到末尾，得到

`S[1], S[2], ..., S[i - 1], S[i + 1], S[i], S[i + 2], ..., S[N]`

这样就交换了 `S[i]` 和 `S[i + 1]`，而没有改变其余字符的位置。

当我们可以交换任意两个相邻的字母后，就可以使用[冒泡排序](https://baike.baidu.com/item/%E5%86%92%E6%B3%A1%E6%8E%92%E5%BA%8F)的方法，仅通过交换相邻两个字母，使得字符串变得有序。因此当 `K = 2` 时，我们可以将字符串移动得到最小的字典序。

当 `K > 2` 时，我们可以完成 `K = 2` 时的所有操作。

```Java [sol1]
class Solution {
    public String orderlyQueue(String S, int K) {
        if (K == 1) {
            String ans = S;
            for (int i = 0; i < S.length(); ++i) {
                String T = S.substring(i) + S.substring(0, i);
                if (T.compareTo(ans) < 0) ans = T;
            }
            return ans;
        } else {
            char[] ca = S.toCharArray();
            Arrays.sort(ca);
            return new String(ca);
        }
    }
}
```

```Python [sol1]
class Solution(object):
    def orderlyQueue(self, S, K):
        if K == 1:
            return min(S[i:] + S[:i] for i in range(len(S)))
        return "".join(sorted(S))
```

**复杂度分析**

* 时间复杂度：当 `K = 1` 时为 $O(N^2)$，否则为 $O(N \log N)$，其中 $N$ 是字符串 `S` 的长度。

* 空间复杂度：当 `K = 1` 时为 $O(N^2)$，否则为 $O(N)$。