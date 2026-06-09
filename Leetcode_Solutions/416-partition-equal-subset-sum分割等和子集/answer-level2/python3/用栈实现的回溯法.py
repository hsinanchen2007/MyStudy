### 解题思路
解题主要是采用的回溯法+剪枝，只不过没有采用递归的形式
### 代码
代码应该还有优化的地方，希望大佬瞥见能提醒我
```python3
class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        nums.sort()
        avg = sum(nums)
        if avg % 2 == 0:
            avg //= 2
            stk = []
            C = []
            #C.append([nums[0]])
            lenth = len(nums)
            stk.append([lenth - 1,nums[-1]])
            #为了避免数组越界的错误，增加一个冗余量
            nums.append(0)
            '''
            如果我没有写错，这是用栈回溯的基本代码，但题目原因需要继续剪枝
            while stk:
                if stk[-1][1] > avg or stk[-1][0] == lenth:
                    stk.pop()
                    #此判断保证回溯时能对上一状态产生影响
                    if stk:
                        stk[-1][0] += 1
                elif stk[-1][1] < avg:
                    stk.append([stk[-1][0]+1, stk[-1][1] + nums[stk[-1][0]+1]])
                elif stk[-1][1] == avg:
                    return True
            return False
            '''
            while stk:
                if stk[-1][1] > avg or stk[-1][0] == -1:
                    stk.pop()
                    #C.pop()
                    #此判断保证回溯时能对上一状态产生影响
                    if stk:
                        stk[-1][0] -= 1
                elif stk[-1][1] < avg:
                    stk.append([stk[-1][0]-1, stk[-1][1] + nums[stk[-1][0]-1]])
                    #C.append(C[-1] + [nums[stk[-1][0]+1]])
                    #print(C[-1])
                elif stk[-1][1] == avg:
                    return True
            return False
        else:
            return False
```