### 解题思路
我的提交执行用时已经战胜 96.61 % 的 cpp 提交记录

//
1. 这里的关键问题是不知道右边界，不过事实上也不要紧，我们只需要知道一个大概的右边界就行了。因此在这里将r称作 fuzzy r。
2. 我们用二进制位移的操作来得到r的大致边界。根据题设，如果找不到就是 INT_MAX，那么就用while来每次向左位移r，r的范围呈指数增长：1, 2, 4, 8, 16, 32...
3. 这里获得的r 是有些浪费的，所以可以根据实际情况调整r跳跃的范围。这里简单起见用 2. 所描述的方法。
4. 接着用二分查找就能解决问题了。注意这里使用的搜索范围是 [l,r)，即左闭右开，所以while(l<r)而不是 while(l<=r)。这里特别提示。


### 代码

```cpp
/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int l = 0, r = 1; // fuzzy r, doesn't matter :)
        while (reader.get(r) != INT_MAX) r <<= 1;

        while (l<r) { // 搜索区间 [l,r) -> [l, mid), [mid+1, r)
            int mid = l + (r-l)/2;
            if (reader.get(mid) == target) return mid;
            else if (reader.get(mid) < target) l=mid+1;
            else if (reader.get(mid) > target) r=mid;
        }

        return -1;
    }
};
```