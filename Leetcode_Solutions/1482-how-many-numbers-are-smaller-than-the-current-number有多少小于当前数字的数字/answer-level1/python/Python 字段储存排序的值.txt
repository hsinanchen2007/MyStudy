
大家好，我的博客是: http://erik-chen.github.io/，欢迎交流！
### 思路

维护一个字典，用来储存每个num和它的排序（注意并列的情况）

### 代码
```python
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        nums2 = sorted(nums)    # 对nums排序
        mapping = {}            # mapping储存num和其序号的键值对
        for i, num in enumerate(nums2):         # 遍历排序后的数组
            if i > 0 and nums2[i] == nums2[i-1]:# 如果某一位跟前一位的值相等，那么它的序号跟前一位一样（并列）
                mapping[nums2[i]] = mapping[nums2[i-1]]
            else:                               # 如果某一位跟前一位的值不等，那么以index为序号
                mapping[nums2[i]] = i
        res = []
        for num in nums:
            res.append(mapping[num])            # res用来储存返回值
        return res
```

