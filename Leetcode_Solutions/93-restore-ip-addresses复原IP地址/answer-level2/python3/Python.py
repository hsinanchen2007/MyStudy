```
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        res = []    # 定义全局变量保存最终结果
        state = []  # 定义状态变量保存当前状态
        deep = 0       # 定义条件变量（一般条件变量就是题目直接给的参数）
        def back(state,q,deep):
            if len(s)-q < 1*(4-deep) or len(s)-q > 3*(4-deep): # 不满足合法条件（可以说是剪枝）
                return
            elif len(s)==q:# 状态满足最终要求
                #（python细节，如果state是字符串，+state ；如果是list，需要用[i for i in state]，和python对象类型有关）
                res.append(".".join([str(i) for i in state]))   # 加入结果
                return 
            # 主要递归过程，一般是带有 循环体 或者 条件体
            for i in range(q,q+3):# 满足执行条件
                # python的状态传递写法，列表 state+[xxx]，字符串 state+"xxx"
                # 传数组不如传下标（可以优化时间）
                temp_num = int(s[q:i+1])
                if len(str(temp_num))!= i-q+1:
                    return
                if 0 <= int(s[q:i+1]) <=255:
                    back(state+[temp_num],i+1,deep+1)
        back(state,0,deep)
        return res
```
