![image.png](https://pic.leetcode-cn.com/7e3b749b04f1b0fbbceae1ed17d01e3e880f914335ba94070c5613d85942ca88-image.png)


```
import math
class Solution:
    def numSquarefulPerms(self, A: List[int]) -> int:
        res = [0]    # 定义全局变量保存最终结果
        state = []  # 定义状态变量保存当前状态
        s = set()
        def is_square(square_num):
            if int(math.sqrt(square_num))**2 == square_num:
                return True
            return False
        def back(state,A):
            if tuple(state) in s:
                return
            s.add(tuple(state))
            if len(A)==0:# 状态满足最终要求
                #（python细节，如果state是字符串，+state ；如果是list，需要用[i for i in state]，和python对象类型有关）
                res[0] += 1
                return 
            # 主要递归过程，一般是带有 循环体 或者 条件体
            for i in range(len(A)):# 满足执行条件
                if len(state) == 0 or is_square(state[-1] + A[i]):
                    back(state+[A[i]],A[:i]+A[i+1:])
                # python的状态传递写法，列表 state+[xxx]，字符串 state+"xxx"
                # 传数组不如传下标（可以优化时间）
        back(state,A)
        return res[0]
```
