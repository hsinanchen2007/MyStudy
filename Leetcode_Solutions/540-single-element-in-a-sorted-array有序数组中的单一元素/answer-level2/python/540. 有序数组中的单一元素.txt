### 解题思路
1. 规律：只有一个单数，其余都双数，所以总数是基数。
2. %：表示余数；//表示：地板数（向下取整）
2. 去除中值与旁边相同的数，目标在剩余数组中基数侧。如果中值本身就是孤立直接输出。
3. 有个坑：在elif循环里，search_odd算上了当前nums[med，所以这里找的是偶数侧。

### 代码

```python3
class Solution:
    def singleNonDuplicate(self, nums: List[int]) -> int:
        l,h = 0,len(nums)-1
        while l < h:
            med = l + (h - l)//2
            search_odd = (med - l)%2 == 0 
            if nums[med] == nums[med-1]:
                if search_odd:
                    h = med -2
                else:
                    l = med + 1
            elif nums[med] == nums[med+1]:
                if search_odd:
                    l = med + 2
                else:
                    h = med - 1
            else:
                return nums[med]
        return nums[l]
```