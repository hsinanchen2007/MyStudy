状态机！！！！！！！ 透了， .1 竟然是合法的 2.e1 也合法。。。。 服了
```
class Solution:
    def isNumber(self, s: str) -> bool:
        dp=[
            [1, 2, 8, -1, -1],
            [-1, 2, 8, -1, -1],
            [-1, 2, 3, 5, -1],
            [-1, 4, -1, 5, -1],
            [-1, 4, -1, 5, -1],
            [6, 7, -1, -1, -1],
            [-1,7,-1,-1,-1],
            [-1,7,-1,-1,-1],
            [-1,4,-1,-1,-1]
        ]
        accept = [2, 3, 4, 7]
        s = s.strip()
        state = 0 
        for i in range(len(s)):
            print(state)
            if s[i] in['+','-']:
                state = dp[state][0]
            elif s[i].isdigit():
                state= dp[state][1]
            elif s[i] == '.':
                state = dp[state][2]
            elif s[i] =='e':
                state = dp[state][3]
            else:
                return False
            if state == -1 : return False 
        print(state)
        return True if state in accept else False
```


