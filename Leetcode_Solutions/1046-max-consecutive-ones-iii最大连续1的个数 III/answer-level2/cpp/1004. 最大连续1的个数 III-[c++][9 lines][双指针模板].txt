## 思路

使用滑动窗口 $[l, r]$, $l$ 和 $r$ 是窗口左右边界指针。

变量 $count$ 统计窗口内 1 的个数，移动右指针。如果发现 $win\_size - count > K$，说明需要收收紧左边界，直到这个差值小于等于 $K$ 为止。每次右边界移动后，使用窗口大小更新返回值。



## 代码

```c++
int longestOnes(vector<int>& A, int K) {
    int res = 0;
    for (int count = 0, l = 0, r = 0; r < A.size(); ++r) {
        if (A[r] == 1) ++count;
        while (r - l + 1 - count > K) if (A[l++]) --count;
        res = max(res, r - l + 1);
    }
    return res;
}
```

## 相似题目

[424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)，这两个题目思路都是一样的。
