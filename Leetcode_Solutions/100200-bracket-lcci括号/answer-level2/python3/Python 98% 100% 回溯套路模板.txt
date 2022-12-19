![image.png](https://pic.leetcode-cn.com/1e1dace121c45ab5037bbfa8f4687681a302ecdc999f8d246d33576c6ea7f0ad-image.png)

 
本题的解法如下：
```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []    # 定义结果变量
        state = ""  # 定义状态变量
        def get_res(state,p,q):
            if p > q:   # 不满足合法条件
                return
            elif len(state) == 2*n: # 达成最终目标的结果
                res.append(state)
                return 
            
            if p>0: # 满足执行条件
                get_res(state+"(",p-1,q)
            if q>0: # 满足执行条件
                get_res(state+")",p,q-1)

        get_res(state,n,n)
        return res
```