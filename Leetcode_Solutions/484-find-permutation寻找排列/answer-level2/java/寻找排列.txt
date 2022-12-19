#### 方法一：数组区间翻转

我们从头开始考虑这个秘密签名。如果秘密以若干个 `I` 开头，那么我们从小到大依次填入数，这样可以满足 `I` 的条件，并且显然这样做字典序是最小的；如果秘密以若干个 `D` 开头，假设有 `k` 个 `D`，那么第一个数至少为 `k + 1`，即按照 `k + 1, k, k - 1, ..., 2, 1` 的顺序填入 `k + 1` 个数，满足 `k` 个 `D` 的条件，并且字典序是最小的。

无论秘密以 `I` 或 `D` 开头，我们都填了从 `1` 开始的若干个数，因此在处理完这些 `I` 或 `D` 之后，剩下的数仍然是一个连续的区间。如果秘密接着出现了若干个 `I`，我们仍然可以从小到大依次填入剩余的数；如果出现了 `k` 个 `D`，我们也可以从剩余的数中选出 `k` 个最小的，从大到小依次填入这些数。

我们发现，如果出现了连续的 `I`，我们会顺序填入数；如果出现了 `D`，我们会逆序填入数。因此我们可以先将所有的数从小到大依次填入，组成 `[1 .. n]` 的排列，随后对于秘密中连续的 `D`，我们将对应位置的区间进行翻转即可。

<![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide1.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide2.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide3.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide4.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide5.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide6.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide7.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide8.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide9.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide10.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide11.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide12.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide13.PNG),![1000](https://pic.leetcode-cn.com/Figures/484/Find_Permutation_ReverseSlide14.PNG)>

```Java [sol1]
public class Solution {
    public int[] findPermutation(String s) {
        int[] res = new int[s.length() + 1];
        for (int i = 0; i < res.length; i++)
            res[i] = i + 1;
        int i = 1;
        while (i <= s.length()) {
            int j = i;
            while (i <= s.length() && s.charAt(i - 1) == 'D')
                i++;
            reverse(res, j - 1, i);
            i++;
        }
        return res;
    }
    public void reverse(int[] a, int start, int end) {
        for (int i = 0; i < (end - start) / 2; i++) {
            int temp = a[i + start];
            a[i + start] = a[end - i - 1];
            a[end - i - 1] = temp;
        }
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。

* 空间复杂度：$O(1)$。