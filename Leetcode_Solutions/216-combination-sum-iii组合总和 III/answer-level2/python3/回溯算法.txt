
解题思路：（1）建立一个1到9的数组nums
（2）因为不能有重复的数字，所以对于第i个节点的选择列表为nums[i+1:]
 (3)进行回溯
代码如下：
```
class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        nums =[1,2,3,4,5,6,7,8,9]
        res =[]
        def backtrack(nums,choose):
            if len(choose) == k and sum(choose)==n:
                res.append(choose)
                return
            for i in range(len(nums)):
                backtrack(nums[i+1:],choose+[nums[i]])
        backtrack(nums,[])
        return res
```
