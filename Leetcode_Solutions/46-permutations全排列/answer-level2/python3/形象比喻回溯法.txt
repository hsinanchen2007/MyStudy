## leetcode_46
1. 回溯法，该题可比喻成此种场景：
    * 假设有一条生产线，生产线旁有一面镜子
    * 镜子中有同样的一条生产线，镜中的生产线也有一面镜子，依次递归
    * 生产工人在一个零件上组装另一个零件之后，复制给镜像中的生产线工人，让他在这个组合零件的基础上重复他的操作
    * 然后把这个刚装上的零件拆掉，安上另一个零件，再复制给镜中，再拆掉，直到零件库中的所有零件都被安装过
    * 如果某一面镜子中发生所有零件都组合到一起的情况，由记录员记录这一组合
    * 重复此过程

```
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        if nums==[]:
            return []
        res = []
        def helper(cur):
            if len(cur)==len(nums):
                res.append(cur[:])
                return
            for num in nums:
                if num in cur:
                    continue
                else:
                    cur.append(num)
                    helper(cur)
                    cur.pop()
        helper([])
        return res
```
