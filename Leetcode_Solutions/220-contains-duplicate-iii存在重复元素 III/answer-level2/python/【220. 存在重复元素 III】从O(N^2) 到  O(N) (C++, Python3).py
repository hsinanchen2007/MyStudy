# 暴力（超时）

## 思路

最简单的思路就是双层循环，找出所有的两两组合。然后逐个判断其是否满足 `nums [i] 和 nums [j] 的差的绝对值最大为 t，并且 i 和 j 之间的差的绝对值最大为 ķ。`

## 代码

```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if abs(nums[i] - nums[j]) <= t and j - i  <= k:
                    return True
        return False
```


**复杂度分析**
- 时间复杂度：$O(N ^ 2)$
- 空间复杂度：$O(1)$


# 暴力 + 剪枝 （超时）

## 思路

上述的内存循环可以稍微优化一下， 之前我们从 i + 1 到 len(nums)，实际上我们只需要 i + 1 到 min(len(nums), i + k + 1)。这样我们的 `j - i  <= k` 也可以省略了。

## 代码

```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        for i in range(len(nums)):
            for j in range(i + 1, min(len(nums), i + k + 1)):
                if abs(nums[i] - nums[j]) <= t:
                    return True
        return False
```

**复杂度分析**
- 时间复杂度：$O(N ^ 2)$
- 空间复杂度：$O(1)$




# 分桶 （通过）

## 思路

我们换种思路。 由于本题对索引有要求，因此直接排序破坏了原来的索引的做法是不行的。 我们考虑使用`桶排序`。

- 我们将数据分到 M 个桶 中。
- 每个数字nums[i] 都被我们分配到一个桶中
- 分配的依据就是 nums[i] // (t + 1)
- 这样相邻桶内的数字最多相差`2 * t + 1`
- 不相邻的桶一定不满足相差小于等于t
- 同一个桶内的数字最多相差`t`

1. 因此如果命中同一个桶内，那么直接返回True
2. 如果命中相邻桶，我们再判断一下是否满足 相差 <= t
3. 否则返回False

需要注意的是，由于题目有索引相差k的要求，因此要维护一个大小为k的窗口，定期清除桶中`过期`的数字。

## 代码

我们使用哈希表来模拟桶，key就是桶号，value就是数字本身。
 
Python 3:
```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        bucket = dict()
        if t < 0: return False
        for i in range(len(nums)):
            nth = nums[i] // (t + 1)
            if nth in bucket:
                return True
            if nth - 1 in bucket and abs(nums[i] - bucket[nth - 1]) <= t:
                return True
            if nth + 1 in bucket and abs(nums[i] - bucket[nth + 1]) <= t:
                return True
            bucket[nth] = nums[i]
            if i >= k: bucket.pop(nums[i - k] // (t + 1))
        return False
```

C++

```c++
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t<0) return false;
        //t+1可能会溢出，所以要+ 1LL
        long long mod = t + 1LL;
        unordered_map<long long,long long> buck;
        for(int i=0;i<nums.size();i++)
        {
            long long nth = nums[i] / mod;
            //可能nums[i]为负数，比如-4 / 5 以及 -4 / 5都等于0，所以负数要向下移动一位
            if(nums[i] < 0) nth--;
            //这里要用find 不能直接[],因为可能本身存储的数字就为0
            if(buck.find(nth)!=buck.end()) 
                return true;
            else if(buck.find(nth-1)!=buck.end() && abs(nums[i] - buck[nth-1]) <= t)
                return true;
            else if(buck.find(nth+1)!=buck.end() && abs(nums[i] - buck[nth+1]) <= t)
                return true;
            buck[nth] = nums[i];
            if(i >= k)
            {
                buck.erase(nums[i - k] / mod);
            }
        }
        return false;
    }
};
```

**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：由于我们最多需要 k 个桶，并且每个桶最多存储 1 个数字，因此空间复杂度为 $O(K)$




欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)