### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def calPoints(self, ops):
        """
        :type ops: List[str]
        :rtype: int
        """
        out = []
        count = 0
        for i in range(len(ops)):
            if ops[i] == "C":
                out.pop()
                count -= 1
            elif ops[i] == "D":
                out.append(out[count-1]*2)
                count += 1
            elif ops[i] == "+":
                out.append(out[count-1] + out[count-2])
                count += 1
            else:
                out.append(int(ops[i]))
                count += 1
        return sum(out)



```