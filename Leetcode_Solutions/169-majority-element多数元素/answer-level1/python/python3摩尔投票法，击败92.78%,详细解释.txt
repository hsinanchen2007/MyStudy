### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
         # major为当前还无法删除的元素，count为其个数。
         # major初值必须为nums中没有的元素。或者也可让 major=nums[0],遍历nums[1:]
        major, count = 0, 0
        for num in nums:
            if not count: # 如果当前count为0，说明当前没有无法删除的元素，则更新major，count
                major = num
                count += 1
            else:   # 若当前count不为0,即存在无法删除的元素
                if num == major:    # 若num==major，说明两者相等，仍无法删除，count增加
                    count += 1
                else:       # 否则说明当前num可以抵消掉一个major，count减1
                    count -= 1
            # 最后将能抵消的不同元素都抵消完了，剩下的major就一定是众数
        return  major

```