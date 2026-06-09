## 思路:

这道题, 难在时间复杂度限定在$O(n)$, 要不排序就可以了!

思路一:集合

集合,查询时间复杂度为$O(1)$

思路二:字典

遍历数组, 用字典(哈希)记录目前与该值可以组成最长连续序列.

直接看代码(有注释)

## 代码:

思路一:

```python [1]
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        nums = set(nums)
        res = 0
        for num in nums:
        	# 判断是否是第一个数字
            if num - 1 not in nums:
                tmp = 1
                while num + 1 in nums:
                    num += 1
                    tmp += 1
                res = max(res, tmp)
        return res
```



```java [1]
class Solution {
    public int longestConsecutive(int[] nums) {
        Set<Integer> num_set = new HashSet<>();
        for (int n : nums) num_set.add(n);
        int res = 0;
        for (int num : num_set) {
            if (!num_set.contains(num - 1)) {
                int tmp = 1;
                while (num_set.contains(num + 1)) {
                    tmp++;
                    num++;
                }
                res = Math.max(res, tmp);
            }
        }
        return res;
    }
}
```

思路二:

```python [2]
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        lookup = {}
        res = 0
        for num in nums:
            if num not in lookup:
                # 判断左右是否可以连起来
                left = lookup[num - 1] if num - 1 in lookup else 0
                right = lookup[num + 1] if num + 1 in lookup else 0
                # 记录长度
                lookup[num] = left + right + 1
                # 把头尾都设置为最长长度
                lookup[num - left] = left + right + 1
                lookup[num + right] = left + right + 1
                res = max(res, left + right + 1)
        return res
```



```java [2]
class Solution {
    public int longestConsecutive(int[] nums) {
        HashMap<Integer, Integer> lookup = new HashMap<>();
        int res = 0;
        for (int num : nums) {
            if (!lookup.containsKey(num)) {
                // 查看左右两边是否可以相连
                int left = (lookup.containsKey(num - 1)) ? lookup.get(num - 1) : 0;
                int right = (lookup.containsKey(num + 1)) ? lookup.get(num + 1) : 0;
                lookup.put(num, left + right + 1);
                // 改变首尾两个长度(换成更长的长度)
                lookup.put(num - left, left + right + 1);
                lookup.put(num + right, left + right + 1);
                res = Math.max(res, left + right + 1);
            }

        }
        return res;
    }
}
```

