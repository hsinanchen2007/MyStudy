### 解题思路
利用字典判断旋转数字

### 代码

```python3
class Solution:
    def rotatedDigits(self, N: int) -> int:
        set_ = {'0':'0', '1':'1', '8':'8', '2':'5', '5':'2', '6':'9', '9':'6'}
        count = 0
        for i in range(1, N + 1):
            temp = str(i)
            flag = False
            for j in temp:
                if j in set_:
                    if set_[j] != j:
                        flag = True
                else:
                    flag = False
                    break
            if flag:
                count += 1
        return count



```