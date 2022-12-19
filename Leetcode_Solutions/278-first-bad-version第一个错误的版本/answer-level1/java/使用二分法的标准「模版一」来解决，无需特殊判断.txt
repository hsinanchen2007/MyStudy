### 解题思路
这题其实是「探索」模块中二分法的[模版二](https://leetcode-cn.com/explore/learn/card/binary-search/210/template-ii/839/)，但是我觉得其实和模版一相通，于是尝试使用模版一来解答，无需增加模版二中的一些判断条件，如：
1. 退出条件依旧是 `lo <= hi)` 而不是 `lo < hi`;
2. 缩小右边界依旧是 `hi = mid - 1` 而不是 `hi = mid`。

减少这些特殊判断能使得代码更加通用、易懂，而不需要纠结于「为什么其中有的部分要改变」这类问题。

### 代码

```java
public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        int lo = 0;
        int hi = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (isBadVersion(mid)) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            } 
        }
        return lo;
    }
}
```