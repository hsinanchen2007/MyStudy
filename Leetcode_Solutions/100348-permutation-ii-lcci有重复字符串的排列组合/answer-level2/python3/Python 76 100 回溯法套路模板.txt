![image.png](https://pic.leetcode-cn.com/0d4dc14086b23421590ca2aeaf8d8c58a3abdd44d2127b68ccf4fb5df3c5116f-image.png)


本题的解法如下
```
class Solution:
    def permutation(self, S: str) -> List[str]:
        res = []    # 定义全局变量保存最终结果
        state = ""  # 定义状态变量保存当前状态
        s = set()   # 定义条件变量
        def back(state, S):
            if state in s:
                return
            s.add(state)
            if len(S)==0: # 状态满足最终要求
                res.append(state)   # 加入结果
                return 
            for i in range(len(S)):
                back(state+S[i],S[:i]+S[i+1:])
        back(state,S)
        return res
```
