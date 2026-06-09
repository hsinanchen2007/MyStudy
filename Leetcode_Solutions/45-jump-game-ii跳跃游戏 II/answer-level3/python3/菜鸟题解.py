### 解题思路
##rick 2020.3.30
##菜鸟题解，勿喷##
##总的想法就是每个元素都需要遍历，元素位置加跳跃能力能够超过终点即返回答案。
##问题在于维护一个最小的step，说明当前元素位置所需要的最小步数
##当前元素位置超过之前能够走的距离时，就应该多走一步了，然而此时也需要不断更新之前的行走距离
##因为判断下一步能到终点就结束，所以返回step+1，但是边界条件只有一个元素的情况就得单独拿出来
##内存消耗好大，不懂
### 代码

```python3
class Solution:
    def jump(self, nums: List[int]) -> int:
        l = len(nums)
        if l == 1:
            return 0
        dis, dis_last, step = 0, 0, 0
        for i in range(0,l):
            if i > dis_last:
                step, dis_last = step+1, dis
            if i + nums[i] >= l-1:
                return step+1
            dis = nums[i] + i if nums[i] + i > dis else dis



            

```