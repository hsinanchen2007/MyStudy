最值问题小编一般的解决思路就是先将数组排序，这样最大值就很直观，我们直接取出，然后再找到数组中元素大于最大数的平方根的那个数的下标，这样之后我们遍历就只需要从这个下标开始进行向后遍历即可，我们在之后的遍历中采用计数器，如果计数器的数值与我们剩余元素的个数相同的话说明我们的所有元素都符合题意，然后再原数组中找到这个最大值的下标进行返回即可。
```
class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        import math
        flag = 0        #全局变量
        n = sorted(nums)    #把数组整体进行赋值，方便最后寻找索引
        count = 0           #用来计算是否遍历了数组中剩下的所有元素
        for i in range(len(n)):          #循环找出最大元素的平方根的索引，这样可以减少下一步的索引量
            if n[i] >= math.sqrt(n[len(n) - 1]):
                flag = i    #后续的测试就从flag对应的下标元素开始
                break
        for i in range(flag, len(n) - 1):       #判断是否满足题意
            if n[len(n) - 1] > n[i] * 2:
                count += 1
        if count == len(n) - 1 - flag:      #如果剩下的元素个数等于计数器的值       
            for i in range(len(nums)):          #寻找最大值的下标
                if nums[i] == n[len(n) - 1]:
                    flag = i
                    return flag
        return -1
```
