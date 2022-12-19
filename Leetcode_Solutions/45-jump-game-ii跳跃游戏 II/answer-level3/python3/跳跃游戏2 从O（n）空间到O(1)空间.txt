解题思路：
1. 从第0个元素起跳，使用跟num同长的数组，记录元素起跳到该下标位置时跳跃的步数
2. 因为被跳跃过的元素肯定时最小次数跳到的，因此无需再更新被跳跃过的元素。因此增加一个需要更新的元素的下标开始位置，来做剪枝操作
3. 当跳跃完所有的元素后，返回最后一个元素的跳跃数即可
```
class Solution:
    def jump(self, nums: List[int]) -> int:
        l = len(nums)
        jump = [0 for i in range(l)]
        jumpStep = 1
        for i in range(l):
            step = nums[i]
            goMax=min(i + step+1, l)
            if jumpStep < goMax:
                for j in range(jumpStep,goMax ):
                    jump[j] = jump[i] + 1
                    jumpStep = jumpStep + 1
        return jump[l - 1]


```

完成了用空间来计数的时候我们也应该感觉到：
1. 相同的步数的元素都是相连的，而且是递增的
2. 这样我们就可以直接每次遍历同一个步数的元素，找到多一步之后能到达的下标范围
3. 之后再继续搜索多一步的范围重复这个搜索过程，知道能到达的下表范围大于或等于元素的下标范围
```
class Solution:
    def jump(self,nums: List[int]):
        l=len(nums)
        step=0
        right=1
        lastLeft=0
        lastRight=1
        while right<l:
            step+=1
            for i in range(lastLeft,lastRight):
                right=max(nums[i]+i+1,right)
            lastLeft=lastRight
            lastRight=right
        return step
```
