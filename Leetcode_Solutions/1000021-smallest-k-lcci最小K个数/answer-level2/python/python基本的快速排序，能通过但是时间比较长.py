### 解题思路
标准的快速排序算法

### 代码

```python
class Solution(object):
    def smallestK(self, arr, k):
        """
        :type arr: List[int]
        :type k: int
        :rtype: List[int]
        """
        def quick_sort(nums):
            #用2个数组来分别保存跟基准相比大或者小的数
            left,right = [],[]
            if(len(nums) < 2):
                return nums
            else:
                base = nums[0]
                #每一次以数组的第一个值为基准，小于等于的放到左边数组，大于的放到右边数组
                left = [num for num in nums[1:] if num <= base]
                right = [num for num in nums[1:] if num > base]
                #如果刚好左边的小数组序列长度符合要求就可以直接返回了，因为题目没有要求返回顺序
                if(len(left) == k):
                    return left
                else:
                    return quick_sort(left) + [base] + quick_sort(right)
        return quick_sort(arr)[:k]
```