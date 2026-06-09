### 解题思路
并查集

### 代码

```python3
class Solution:
    def equationsPossible(self, equations: List[str]) -> bool:
        abcs = list(range(0, 26))
        for equation in equations:
            if equation[1] == '=':
                val0 = ord(equation[0]) - ord('a')
                while abcs[val0] != val0:
                    val0 = abcs[val0]

                val3 = ord(equation[3]) - ord('a')
                while abcs[val3] != val3:
                    val3 = abcs[val3]
                
                if abcs[val0] != abcs[val3]:
                    abcs[val3] = abcs[val0]
                

        for equation in equations:
            if equation[1] == '!':

                val0 = ord(equation[0]) - ord('a')
                while abcs[val0] != val0:
                    val0 = abcs[val0]
                
                val3 = ord(equation[3]) - ord('a')
                while abcs[val3] != val3:
                    val3 = abcs[val3]

                if val0 == val3:
                    return False
        
        return True
                
            
```