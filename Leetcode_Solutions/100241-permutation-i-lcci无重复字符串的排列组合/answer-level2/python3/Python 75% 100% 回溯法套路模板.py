![image.png](https://pic.leetcode-cn.com/e78a17e6bb5bf009612270646d6bc09dcd2068b5b920a6cb19120ca64b885f01-image.png)



本题的解法如下：


```
class Solution:
    def permutation(self, S: str) -> List[str]:
        res = []    # 定义全局变量保存最终结果
        state = ""  # 定义状态变量保存当前状态
        def back(state, S):
            if len(S)==0: # 状态满足最终要求
                res.append(state)   # 加入结果
                return 
            for i in range(len(S)):
                back(state+S[i],S[:i]+S[i+1:])
        back(state,S)
        return res
```
