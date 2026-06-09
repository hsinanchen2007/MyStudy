![image.png](https://pic.leetcode-cn.com/2d618b94e598a9afd834d2cbc2ccd2f8aa5d0836188cb04fd12c154546865cce-image.png)


```
class Solution:
    def permutation(self, s: str) -> List[str]:
        res = []    # 定义全局变量保存最终结果
        state = ""  # 定义状态变量保存当前状态
        exist = set()       # 定义条件变量（一般条件变量就是题目直接给的参数）
        def back(state,s):
            if state in exist:# 不满足合法条件（可以说是剪枝）
                return
            elif len(s)==0:# 状态满足最终要求
                #（python细节，如果state是字符串，+state ；如果是list，需要用[i for i in state]，和python对象类型有关）
                res.append(state)   # 加入结果
                exist.add(state)
                return 
            # 主要递归过程，一般是带有 循环体 或者 条件体
            for i in range(len(s)): # 满足执行条件
                # python的状态传递写法，列表 state+[xxx]，字符串 state+"xxx"
                # 传数组不如传下标（可以优化时间）
                
                back(state+s[i],s[:i]+s[i+1:])
        back(state,s)
        return res
```
