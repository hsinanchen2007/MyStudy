```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        s = [0] * len(nums)
        l = sorted(nums)  #进行排序
        lk = {}
        for j in range(len(nums)):
            if l[j] not in lk.keys(): #取每个数第一次出现的位置
                lk[l[j]] = j          #即是当前数大于其他数的个数
        for i in range(len(nums)):
            s[i] = lk[nums[i]]        #抽取字典中保存的值
        return s
```



举例[3, 2, 1, 1, 4, 4]，排序后为[1, 1, 2, 3, 4, 4]，对应数字第一次出现的取值字典为[1:0, 2:2, 3:3, 4:4]。
描述的不好，多见谅。