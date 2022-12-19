### 解题思路
坑1：空数组
坑2：重复元素

### 代码

```python3
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        
        # 贪心 + 二分， 尽管不是特别理解，简单来说就是维护一个递增数组
        # 当nums中元素大于这个数组的最大值（即最后一个元素）时，就把这个元素加入数组
        # 否则就把这个元素替换到 a<b <c,中b的位置
        if not nums:
            return 0

        length = 1
        d = [nums[0]]

        for i in range(1,len(nums)):
            print(d)
            if d[length - 1] < nums[i]:
                d.append(nums[i])
                length += 1
            else:
                # 二分查找，从d中找到b，替换
                start = 0
                end = length - 1

                while start < end - 1:
                    mid = (start + end) // 2
                    if nums[i] < d[mid]:
                        end = mid
                    else:
                        start = mid
                if nums[i] == d[start] or nums[i] == d[end]:
                    continue
                if nums[i] < d[start]:
                    d[start] = nums[i]
                else:
                    d[end] = nums[i]
        return length
```