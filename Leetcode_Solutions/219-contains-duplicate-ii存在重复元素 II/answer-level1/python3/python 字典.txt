### 解题思路
![图片.png](https://pic.leetcode-cn.com/10fa24e82b97b02c9fde6beaff2e66aa38133ad7cad8e5d9d9a69c8e001e33ee-%E5%9B%BE%E7%89%87.png)
维护一个字典，key值为元素值，value为索引值的列表
当出现重复元素a的时候，就把当前的索引值和dic[a]的最后一个元素比较
如果大于k，则前面的索引值与当前索引值都大于k，将当前索引值插入
否则小于等于k，说明前面的索引值至少有一个大于当前索引值，直接返回True
### 代码

```python
class Solution(object):
    def containsNearbyDuplicate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: bool
        """
        dic={}
        for i,n in enumerate(nums):
            if n not in dic: dic[n]=[i]
            else:
                if abs(dic[n][-1]-i)>k: dic[n].append(i)
                else: return True
        return False
```