从后往前判断，因为要选择最优，所以要保存可能的最优，可以用栈的方式来保存，栈单元是(跳数， 数组序号)，栈最上面的跳数最小，数组序号由于从后到前遍历所以从下到上是降序的，当判断到当前序号的跳数小于等于栈顶的跳数，那么就pop出栈顶，因为当前元素比当前栈顶更优，最后push进该元素

栈思路代码：
```
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        if not nums:
            return 0

        n = len(nums)
        stack = [(0, n-1)]
        for i in xrange(n-2, -1, -1):
            j = len(stack)-1
            while j >= 0 and i + nums[i] >= stack[j][1]:
                j -= 1
            if j+1 == len(stack):
                continue
            cur_min = stack[j+1][0]+1
            while stack and stack[-1][0] >= cur_min:
                stack.pop()
            stack.append((cur_min, i))
        return stack[-1][0] if stack[-1][1] == 0 else stack[-1][0]+1
```
