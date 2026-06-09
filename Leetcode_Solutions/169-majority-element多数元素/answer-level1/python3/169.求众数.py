### 解题思路
方法1.
得到列表中的不重复元素：list转为set
统计元素频率：遍历集合
方法2.
对列表进行排序，众数的数量超过一半，因此中位数就是众数。
方法3.
统计元素频率转为字典：collections.Counter()
返回字典中最大值对应的键：max(counts.keys(), key=counts.get)

### 代码

```python3
class Solution:
    '''
    # 统计元素频数
    def majorityElement(self, nums: List[int]) -> int:
        max_count = 0
        for i in set(nums):
            count =nums.count(i)
            if count>max_count:
                max_count = count
                mode_number = i
        return mode_number
    '''
    '''
    # 排序
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        mode_number = nums[len(nums)//2]
        return mode_number
    '''

    def majorityElement(self, nums):
        counts = collections.Counter(nums)
        return max(counts.keys(), key=counts.get)

```