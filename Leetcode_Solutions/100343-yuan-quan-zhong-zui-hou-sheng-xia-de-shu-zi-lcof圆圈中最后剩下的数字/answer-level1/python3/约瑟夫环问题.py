### 解题思路
两种方法：

1.模拟（超时）
2.递推公式 （需要多思考才能体会）
```
    f(n) = (f(n-1)+m)%n
```


### 代码

1.模拟
```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        
        peoples = [True]*n
        call = m-1
        count = 0
        while any(peoples):
            for index,people in enumerate(peoples):
                if people:
                    if count == call:
                        peoples[index]=False
                        res = index
                        count = 0
                    else:
                        count+=1
        return res
```


2.递推
```python3
class Solution:
    def lastRemaining(self, n: int, m: int) -> int:
        last = 0
        for i in range(2,n+1):
            last = (last+m)%i
        return last
        
```