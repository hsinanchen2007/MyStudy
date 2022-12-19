### 解题思路
利用set的元素唯一性，作为false的判定条件
至于无限不循环的可能性不存在，建议看官方题解，非常厉害的解释

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        ans=set()
        ans.add(n)
        while n!=1:
            n=sum(int(i)**2 for i in list(str(n)))
            #print(ans)
            if n in ans:
                return False
            else:
                ans.add(n)
        return True
```