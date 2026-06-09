### 解题思路
![5352c3277c90c695eec54ada535193e.png](https://pic.leetcode-cn.com/15b91127fafdb0c14b838661c970f3eb54d8845486bbb9a5ebe141a91e167cf8-5352c3277c90c695eec54ada535193e.png)

关键点是剪枝条件，详见代码


### 代码
```python3
class Solution:
    def combinationSum(self, nums: List[int], target: int) -> List[List[int]]:
        # 通过两个剪枝条件去重及减少搜索次数
        def spilit(num,tmp):
            if num in numset: # 存储可行解
                res.append(tmp+[num]) 
            if num < minnum: # 当数字不能再分解时，停止递归
                return    
            for i in nums:
                if i > num//2:   # 剪枝条件1:左节点大于右节点
                    continue
                if len(tmp) >= 1 and i < tmp[-1]: # 剪枝条件2:左节点小于‘叔节点’（父节点的兄弟节点）
                    continue
                spilit(num-i,tmp+[i]) # 直接传递参数，减少回溯步骤
            return
        numset = set(nums)
        minnum = 2*min(nums) # 最小的可分解的数
        res = []
        spilit(target,[])
        return res
```