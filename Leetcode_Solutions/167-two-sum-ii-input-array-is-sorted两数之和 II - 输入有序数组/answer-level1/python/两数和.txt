### 解题思路
此处撰写解题思路

### 代码

```python


"""
二分查找
"""
class Solution(object):
    def binary_search(self, numbers, start, target):
        left = start
        right = len(numbers) - 1
        while(left <= right):
            mid = (left + right)//2
            if numbers[mid] == target:
                return mid
            elif numbers[mid] > target:
                right = mid - 1
            elif numbers[mid] < target:
                left = mid + 1
        return -1

    def twoSum(self, numbers, target):
        """
        :type numbers: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(numbers)):
            tmp = target - numbers[i]
            right_idx = self.binary_search(numbers, i+1, tmp)
            if right_idx != -1:
                return [i+1, right_idx+1]



# """
# 字典查找
# """
# class Solution(object):
#     def twoSum(self, numbers, target):
#         """
#         :type numbers: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         mapper = {}
#         for i in range(len(numbers)):
#             mapper[numbers[i]] = i + 1
        
#         for i in range(len(numbers)):
#             tmp = target - numbers[i]
#             if mapper.get(tmp):
#                 return [i+1, mapper[tmp]]

# """
# 暴力搜索
# """
# class Solution(object):
#     def twoSum(self, numbers, target):
#         """
#         :type numbers: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         for i in range(len(numbers)-1):
#             tmp = target - numbers[i]
#             for j in range(i+1, len(numbers)):
#                 if tmp == numbers[j]:
#                     return [i+1,j+1]


```