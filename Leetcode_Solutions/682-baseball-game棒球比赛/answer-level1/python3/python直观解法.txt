```
class Solution:
    def calPoints(self, ops: list) -> int:
        valid = []
        for i in range(len(ops)):
            if ops[i] not in ("C","D","+"):
                valid.append(int(ops[i]))
            if ops[i] == "C":
                valid.pop(-1)
            if ops[i] == "D":
                tmp = valid[-1]
                valid.append(tmp*2)
            if ops[i] == "+":
                tmp_1 = valid[-1]+valid[-2]
                valid.append(tmp_1)
        return sum(valid)
```
