### 解题思路
规规矩矩一步一步走，边走边试探，中间到了某一步前进步数为0了则返回False


### 代码

```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        size=len(nums)
        if size==1:
            return True
        step=nums[0]  #记录当前位置下能向前走几步，如果没有到最后就变成0了，就返回False
        for i in range(size-1):
            if step==0:
                return False
            if nums[i]==0 and step<2:
                return False
            step=max(step-1,nums[i])

        return step>0
```