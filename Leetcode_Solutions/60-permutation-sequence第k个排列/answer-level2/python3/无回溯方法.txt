# 每次找到其所属的堆，然后迭代下去

```python

class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        result = ""
        record = []
        dig_no_use = list(range(1, n+1))   # 没有使用的数字
        temp = 1
        dig_cur = k
        for i in range(1, n):
            temp = temp * i
            record.append(temp)
        record = record[::-1]
        
        for x in record:
            choose_index = (dig_cur - 1) // x  # 找到所属的组
            result += str(dig_no_use[choose_index])  # 结果加入
            dig_no_use.pop(choose_index)
            dig_cur = dig_cur % x  # 更新数字
        
        result += str(dig_no_use[0])  # 将最后剩下的加到最后
        return result
```