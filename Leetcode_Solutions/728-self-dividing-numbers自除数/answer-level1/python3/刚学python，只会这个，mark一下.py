### 解题思路

最简单的思路，目前只会这个，加油！

### 代码

```python3
class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        list1 = []
        nums = 0
        for i in range(left,right+1):
            if "0" not in str(i):
                for j in str(i):
                    if i % int(j) == 0:
                        nums += 1
            if nums == len(str(i)):
                list1.append(i)
            nums = 0
        return list1
```