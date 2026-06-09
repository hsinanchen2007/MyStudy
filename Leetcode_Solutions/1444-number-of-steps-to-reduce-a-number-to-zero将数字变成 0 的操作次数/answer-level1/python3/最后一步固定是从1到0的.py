### 解题思路
- 利用while判断num是否大于1，如果是，继续判断num的奇偶性进行相应的操作
- 否则直接令count(用于计数的变量)自增1再return
- 因为不管num的奇偶性，最后一步肯定是从1-->0的

### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        if num == 0:
            return 0
        count = 0
        while num>1:
            if num % 2==0:
                num /=2
                count +=1
            else:
                num -=1
                count +=1 
        count += 1
        return count
```