1、循环调用本函数，设置函数结束条件，如果列表为空，则结束；
2、遍历列表中每一元素，并copy一个与nums相同值的列表，删除遍历中的这个元素；
3、如果函数返回为空列表，则代表已经遍历到最后一个元素，把最后一个元素加入ans，并把ans append到结果集res；
4、循环此过程，就可以得到全部的排列组合。
```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if not nums:
            return []
        res = []
        for num in nums:
            lis = nums[:]
            lis.remove(num)
            ans1 = self.permute(lis)
            if ans1:
                for i in ans1:
                    ans = [num] + i
                    res.append(ans)
            else:
                ans = [num]
                res.append(ans)
        return res
```

