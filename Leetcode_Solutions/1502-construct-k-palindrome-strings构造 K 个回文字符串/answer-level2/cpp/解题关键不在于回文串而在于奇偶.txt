题目中虽然出现了回文串，但是这道题因为可以把字符串拆散**重组**，所以回文串就不重要了，重要的是回文串的构成：

>左右两边的元素都是两两相对，即偶数个；中间的元素要么是两个相同的，要么是单独的一个。

所以，只需要统计中间位置出现的元素即可。换句话来说，如果某个字符出现了偶数次，那么它可以被放置到两边的位置；如果某个字符仅仅出现了一次，那么它只能放在中间。放在中间的元素如果大于需要划分的字串`k`，那么无论如何我们也组合不出来`k`个子串。相反，如果等于`k`很好理解，小于`k`的情况那么中间放两个同样的元素补齐即可。

```C++ []
class Solution {
  public:
    bool canConstruct(string s, int k) {
        if (s.size() < k) return false;
        if (s.size() == k) return true;
        std::unordered_map<char, int> umap;
        for (char &c : s) umap[c]++;
        int res = 0;
        for (auto &p : umap)
            if (p.second % 2 == 1) res++;
        return res <= k;
    }
};
```