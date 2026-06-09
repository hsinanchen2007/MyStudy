```
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        res = [0]    # 定义全局变量保存最终结果
        state = set()  # 定义状态变量保存当前状态
        arr = [set(i) for i in arr if len(i)==len(set(i))]
        def back(state,q):
            if len(state)>res[0]:# 状态满足最终要求
                #（python细节，如果state是字符串，+state ；如果是list，需要用[i for i in state]，和python对象类型有关）
                res[0] = len(state)
            # 主要递归过程，一般是带有 循环体 或者 条件体
            for i in range(q,len(arr)):# 满足执行条件
                # python的状态传递写法，列表 state+[xxx]，字符串 state+"xxx"
                # 传数组不如传下标（可以优化时间）
                if len(state)+len(arr[i]) == len(state|arr[i]):
                    back(state|arr[i],i+1)
        back(state,0)
        return res[0]
```
