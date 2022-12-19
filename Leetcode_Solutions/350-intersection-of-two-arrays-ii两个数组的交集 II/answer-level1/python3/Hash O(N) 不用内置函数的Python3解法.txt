## 思路
+ 建立一个哈希表，键为nums1的数，值为这个数出现的次数
+ 遍历num2,当num2的数出现在哈希表中，将它添加到答案里，同时更新哈希表，让其出现次数减一。
## 代码
```python
from collections import defaultdict
class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        dic, ans = defaultdict(int), list()
        for i in nums1: dic[i] += 1
        for i in nums2:
            if dic[i] != 0:
                ans.append(i)
                dic[i] -= 1
        return ans
```
+ `defaultdict(int)`项对第一次出现的键会初始化一个0的值
+ 这题也可以使用`Counter`直接统计出字符出现的次数，和手动遍历是一样的。

## 复杂度分析
假设num1有M项，num2有m项，其中M>m，则
+ 时间复杂度 $O(M+m)$
+ 空间复杂度 $O(m)$