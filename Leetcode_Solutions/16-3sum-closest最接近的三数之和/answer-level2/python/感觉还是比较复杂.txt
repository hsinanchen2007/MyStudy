### 解题思路
三种情况：
1、序列中三数和最大的如果小于target，则整个序列任意三个数的和都小于target，那么和最大的距离target最近
2、序列中三数和最小的如果大于target，则整个序列任意三个数的和都大于target，那么和最小的距离target最近
3、将序列中所有三数之和求出，放在list中，然后排序，如果位置i的数-target <0并且位置i+1的数-target>0,那么判断他们俩谁距离target近即可

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        #near_n=""
        #near_index=[0]*3
        #near_r=0
        co_list=list()
        if nums[0]+nums[1]+nums[2] > target:
            return nums[0]+nums[1]+nums[2]
        if nums[-1]+nums[-2]+nums[-3] < target:
            return nums[-1]+nums[-2]+nums[-3]
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                for k in range(j+1,len(nums)):
                    sum_tre=nums[i]+nums[j]+nums[k]
                    if abs(sum_tre-target) == 0:
                        return sum_tre
                    co_list.append(sum_tre)
        co_list.sort()
        #print(co_list)
        for i in range(len(co_list)-1):
            if co_list[i+1]-target > 0 and target-co_list[i] > 0:
                if abs(co_list[i]-target) < abs(target-co_list[i+1]):
                    return co_list[i]
                else:
                    return co_list[i+1]
```