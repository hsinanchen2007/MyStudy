import collections
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
       b=collections.Counter(nums).most_common(1) 返回出现次数最大的列表
       c =b.pop(0) 提取列表中的第一个元素，实则为一个元组
       return c[0] 提取元组中第一个元素