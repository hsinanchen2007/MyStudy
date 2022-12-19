这里使用两个不同片的二分模板。分别是模板二（求山峰）和模板一（搜索值）。

因为题目说了，相邻元素一定不相同，因此可以使用模板一直接搜索。如果相邻元素可以相同，且只能返回最左边符合条件的那个，那你只能使用模板二啦。

另外还有模板三（我几乎不用），模板四（也没怎么用过），可以参考这个[704-二分查找](https://leetcode-cn.com/problems/binary-search/solution/704-er-fen-cha-zhao-cer-fen-mo-ban-by-ivan_allen/)


```cpp
int findInMountainArray(int target, MountainArray &a) {
    // 先使用 lowerbound 模板求山峰
    int lo = 0, hi = a.length() - 1;
    while (lo < hi) {
        int mid = lo + (hi - lo >> 1);
        if (a.get(mid) < a.get(mid + 1)) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    int peak = lo;
    // 加速
    if (target > a.get(peak)) return -1;

    // 其实你可以再优化一下，如果 target <= a[peak]，答案肯定在左侧
    // 这里就偷懒一下，先找左边，找不到再找右边。复杂度没啥变化，因为二分真的太快了，10000 个数，最多搜索 13 到 14 次
    
    // 先找左边
    lo = 0, hi = peak;
    while (lo <= hi) {
        int mid = lo + (hi - lo >> 1);
        if (target == a.get(mid)) {
            return mid;
        } else if (target < a.get(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    // 在右边找。
    lo = peak + 1, hi = a.length() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo >> 1);
        if (target == a.get(mid)) {
            return mid;
        } else if (target > a.get(mid)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }
    
    return -1;
}
```
