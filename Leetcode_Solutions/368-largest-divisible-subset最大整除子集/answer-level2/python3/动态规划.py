暴力动态规划，时间复杂度略大。

```
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        nums.sort()                                #先排序
        res = [[i] for i in nums]                  #生成组合列表
        for i in range(len(nums)):
            tmp = []
            j = i -1
            while j >= 0:                          #找出当前位置之前所有可能的组合
                if nums[i] % nums[j] == 0:
                    tmp.append(res[j])
                j -= 1
            cnt = [0,0]
            if tmp:                                #将当前位置之前所有可能组合中最长的数组存入到组合列表
                for k in range(len(tmp)):
                    if len(tmp[k]) > cnt[1]:
                        cnt[0] = k
                        cnt[1] = len(tmp[k])
                res[i] = tmp[cnt[0]] + res[i]
        cnt = [0, 1]
        for i in range(len(res)):                  #返回最长的子数组
            if len(res[i]) > cnt[1]:
                cnt[0] = i
                cnt[1] = len(res[i])
        return res[cnt[0]]
```
代码简化一下：
```
class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        if not nums:
            return []
        nums.sort()
        res = [[i] for i in nums]
        largest = res[0]
        for i in range(len(nums)):
            tmp = []
            j = i -1
            while j >= 0:
                if nums[i] % nums[j] == 0 and len(res[j]) > len(tmp):
                    tmp = res[j]
                j -= 1
            res[i] = tmp + res[i]
            if len(res[i]) > len(largest):
                largest = res[i]
        return largest
```

