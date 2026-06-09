### 解题思路
记录上次操作末尾字符长度为1的个数

### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        num = str(num) 
        last = 1  # 记录上次操作末尾编码长度为1的个数
        res = 1
        for i in range(1, len(num)):
            if num[i-1] == '1' or (num[i-1] == '2' and int(num[i]) <= 5): # 可以和上一次末尾长度为1的，组成一个长度为2的编码的条件
                temp = res
                res += last
                last = temp
            else:
                last = res
        return res

```