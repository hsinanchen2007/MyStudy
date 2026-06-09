思路很简单，遍历一遍即可
使用哈希表，在存入哈希表的同时，保留max_k和max_v的值
（不过要注意边界条件，当数组只有一个元素的时候）


class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        if len(nums)==1:
            return nums[0]
        d={}
        max_v=0
        max_k=0
        for i in nums:
            if d.get(i) is None:
                d[i]=1
            else:
                d[i]+=1
                if max_v<d[i]:
                    max_v=d[i]
                    max_k=i
        return max_k