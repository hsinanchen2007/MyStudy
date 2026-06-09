####  方法一：记录存在的字母
**算法：**
- 我们可以扫描 `letters` 记录字母是否存在。我们可以用大小为 26 的数组或者 `Set` 来实现。
- 然后，从下一个字母（从比目标大一个的字母开始）开始检查一下是否存在。如果有的话则是答案。

```Python [ ]
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        seen = set(letters)
        for i in xrange(1, 26):
            cand = chr((ord(target) - ord('a') + i) % 26 + ord('a'))
            if cand in seen:
                return cand
```

```Java [ ]
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        boolean[] seen = new boolean[26];
        for (char c: letters)
            seen[c - 'a'] = true;

        while (true) {
            target++;
            if (target > 'z') target = 'a';
            if (seen[target - 'a']) return target;
        }
    }
}
```


**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 指的是 `letters` 的长度，我们扫描数组的每个元素。
* 空间复杂度：$O(1)$。`seen` 最大的空间为 26。


####  方法二：线性扫描
**算法：**
由于 `letters` 已经有序，当我们从左往右扫描找到比目标字母大字母则该字母就是答案。否则(`letters` 不为空)答案将是 `letters[0]`。

```Python [ ]
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        for c in letters:
            if c > target:
                return c
        return letters[0]
```

```Java [ ]
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        for (char c: letters)
            if (c > target) return c;
        return letters[0];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(N)$。$N$ 指的是 `letters` 的长度，我们扫描数组的每个元素。
* 空间复杂度：$O(1)$。只使用了指针。


####  方法三：二分查找
**算法：**
- 如方法二一样，我们想要在有序数组中查找比目标字母大的最小字母，可以使用二分查找：让我们找到最右边的位置将 `target` 插入 `letters` 中，以便它保持排序。
- 二分查找分几轮进行，在每一轮中我们保持循环始终在区间 `[lo，hi]`。让 `mi = (lo + hi) / 2`。若 `letters[mi] <= target`，则我们修改查找区间为 `[mi + 1, hi]`，否则，我们修改为 `[lo, mi]`
- 最后，如果插入位置是最后一个位置 `letters.length`，则返回 `letters[0]`。这就是模运算的运用。

```Python [ ]
class Solution(object):
    def nextGreatestLetter(self, letters, target):
        index = bisect.bisect(letters, target)
        return letters[index % len(letters)]
```

```Java [ ]
class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int lo = 0, hi = letters.length;
        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (letters[mi] <= target) lo = mi + 1;
            else hi = mi;
        }
        return letters[lo % letters.length];
    }
}
```

**复杂度分析**

* 时间复杂度：$O(\log N)$。$N$ 指的是 `letters` 的长度，我们只查看数组中的 $\log n$ 个元素。
* 空间复杂度：$O(1)$。只使用了指针。