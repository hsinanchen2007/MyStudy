### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        a=[]
        for i in range(1,n+1):
            if i%3==0 and i%5==0:
                a.append("FizzBuzz")
            elif i%3==0:
                a.append("Fizz")
            elif i%5==0:
                a.append("Buzz")
            else:
                a.append(str(i))
        return a
```
执行用时 :
32 ms
, 在所有 python3 提交中击败了
99.89%
的用户
内存消耗 :
13.7 MB
, 在所有 python3 提交中击败了
99.38%
的用户