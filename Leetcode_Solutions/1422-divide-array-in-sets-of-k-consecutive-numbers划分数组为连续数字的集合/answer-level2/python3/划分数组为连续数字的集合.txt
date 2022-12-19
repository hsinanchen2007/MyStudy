### 方法一：排序 + 模拟

本题和 [846. 一手顺子](https://leetcode-cn.com/problems/hand-of-straights/) 除数据范围有略微差异之外完全相同。

我们首先考虑数组 `nums` 中最小的数 `a0`，显然 `a0` 一定是某个集合的最小值，且这个集合包含 `[a0, a0 + 1, ..., a0 + k - 1]` 共 `k` 个数，因此我们划分出了一个集合，可以将这 `k` 个数从 `nums` 中移除。我们接着考虑数组 `nums` 剩余元素中最小的数 `a1`，同理 `a1` 也是某个集合的最小值，且这个集合包含 `[a1, a1 + 1, ..., a1 + k - 1]` 共 `k` 个数，我们同样划分出了一个集合，并将这 `k` 个数从 `nums` 中移除。

我们重复这样的操作，直到 `nums` 中的所有数都被移除（返回 `True`） 或在某一步最小值为 `ai` 时，数组 `nums` 的剩余元素并不包含 `[ai, ai + 1, ..., ai + k - 1]` 这 `k` 个数（返回 `False`）。

那么应当使用什么数据结构来实现这个算法呢？由于我们需要从小到大地考虑数组 `nums` 中的数，并且需要查询 `nums` 剩余元素中是否包含某些数，因此我们可以使用有序映射（TreeMap）来存储 `nums` 中所有的数。有序映射中的每个键值对 `(num, occ)` 表示数 `num` 在数组 `nums` 中出现了 `occ` 次。由于我们使用的映射（Map）是有序的，因此我们可以按照键的顺序从小到大遍历这些键值对。当我们遍历到键值对 `(num, occ)` 时，即表示数组 `nums` 剩余元素中最小的数为 `num`，且出现了 `occ` 次。此时我们依次查询 `num + 1, num + 2, ..., num + k - 1` 出现的次数是否均不少于 `occ`，如果是，那么我们就得到了 `occ` 个集合 `[num, num + 1, ..., num + k - 1]`，并把这些元素全部移除；如果不是，那么我们就无法将剩余的元素划分成一些由 `k` 个连续数字组成的集合。

注意：由于 `Python` 语言中不提供有序映射，因此我们需要先使用无序映射（即哈希映射，例如 `Python` 中的 `dict` 或 `collections.Counter`），再将无序映射中的键进行排序，通过遍历排序后的键来达到从小到大遍历键值对的效果。

```C++ [sol1-C++]
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> s;
        for (int num: nums) {
            ++s[num];
        }
        for (auto iter = s.begin(); iter != s.end(); ++iter) {
            int num = iter->first;
            int occ = iter->second;
            if (occ > 0) {
                auto it = next(iter);
                for (auto i = 1; i < k; ++i, ++it) {
                    if (it != s.end() && it->first == num + i && it->second >= occ) {
                        it->second -= occ;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```

```C++ [sol1-C++17]
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> s;
        for (int num: nums) {
            ++s[num];
        }
        for (auto& [num, occ]: s) {
            if (occ > 0) {
                for (int i = num + 1; i < num + k; ++i) {
                    if (s.count(i) && s[i] >= occ) {
                        s[i] -= occ;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
```

```Python [sol1-Python3]
class Solution:
    def isPossibleDivide(self, nums: List[int], k: int) -> bool:
        s = collections.Counter(nums)
        ordered_nums = sorted(s)
        for num in ordered_nums:
            occ = s[num]
            if s[num] > 0:
                for i in range(num + 1, num + k):
                    if s[i] >= occ:
                        s[i] -= occ
                    else:
                        return False
        return True
```

**复杂度分析**

- 时间复杂度：$O(N \log N)$，其中 $N$ 是数组 `nums` 的长度。我们需要使用 $O(N \log N)$ 的时间将数组 `nums` 中的所有数放入有序映射中，$O(N)$ 的时间遍历有序映射中的所有键值对，总计最多 $O(N \log N)$ 的时间移除（在上面的代码中，我们实际上只是修改了键值对中的值，而没有真正地将一个键值对移除）所有连续数字组成的集合，因此总时间复杂度为 $O(N \log N)$。

- 空间复杂度：$O(N)$，即为有序映射使用的空间。