### 解题思路
确定有限自动机：根据每一位字符进行状态转移即可，方框表示合法的结束状态。图中未标出的状态9表示字符串末尾的空格。
![IMG_3732.jpg](https://pic.leetcode-cn.com/21bb5c376b6f9d17f85a2cb5149cf663e15581a3cc4e7092d994bd8df5c0bd92-IMG_3732.jpg)
![IMG_3733.jpg](https://pic.leetcode-cn.com/b2f30ff15f23955ba82c297a892eab2a4fa53ba2bb9760fca83bb8b85fd3d41b-IMG_3733.jpg)

### 代码

```python3
class Solution:
    def isNumber(self, s: str) -> bool:
        if not s:return False

        transTable = [
            [1,2,7,-1,-1,0],
            [-1,2,7,-1,-1,-1],
            [-1,2,3,4,-1,9],
            [-1,3,-1,4,-1,9],
            [6,5,-1,-1,-1,-1],
            [-1,5,-1,-1,-1,9],
            [-1,5,-1,-1,-1,-1],
            [-1,8,-1,-1,-1,-1],
            [-1,8,-1,4,-1,9],
            [-1,-1,-1,-1,-1,9]
        ]

        cols = {
            "sign":0,
            "number":1,
            ".":2,
            "exp":3,
            "other":4,
            "blank":5  
        }

        def get_col(c):
            if c.isdigit():return 'number'
            elif c in {'+','-'}:return 'sign'
            elif c == '.':return '.'
            elif c in {'E','e'}:return 'exp'
            elif c == ' ':return 'blank'
            else:return 'other'

        legal_state = {2,3,5,8,9}
        state = 0
        for c in s:
            state = transTable[state][cols[get_col(c)]]
            if state == -1:return False
        return True if state in legal_state else False

```