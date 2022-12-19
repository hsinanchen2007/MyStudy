主体思想：先排序，记录每个数的个数，和每个数的初始下标。分别存在两个列表里，构建字典。将字典排序，输出前K个高频元素
```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        if len(nums)==1:
            return nums
        nums = sorted(nums)
        count_dig = 0
        index1 = []
        count1 = []
        for i in range(len(nums)-1):
            count_dig+=1
            if nums[i]!=nums[i+1]:
                count1.append(count_dig)
                index1.append(i-count_dig+1)
                count_dig=0
        if nums[len(nums)-1]!=nums[len(nums)-2]:
            count1.append(1)
            index1.append(len(nums)-1)
        else:
            count1.append(count_dig+1)
            index1.append(i-count_dig+1)
        dic = {}
        for i in range(len(count1)):
            dic[index1[i]] = count1[i]
        dic = sorted(dic.items(), key=lambda x:x[1], reverse=True)
        re_nums = []
        ite = 1
        for key,value in dic:
            if ite<=k:
                re_nums.append(nums[key])
                ite+=1
            else:
                break
        return re_nu
```
