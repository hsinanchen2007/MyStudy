### 解题思路
根据题目描述，不断循环下去，最后的结果不是无限循环就是会得到1。无限循环的话，不是快乐数，得到1的话是快乐数。因为无限循环肯定会出现之前出现的数值，所以使用哈希表来解决。
将每次计算得到的数值和该数字作为键值对存入哈希表中，如果在哈希表中查到已经有了数值，说明开始循环了，不是快乐数。否则终究会得到1.

### 代码

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        dic={}
        while True:
            if n in dic:
                return False
            elif n==1:
                return True
            else:
                temp=list(str(n))
                num=0
                for t in temp:
                    num+=int(t)**2
                dic[n]=num
                n=num
```