题目对快乐数的描述：平方和最终为1就快乐，**不快乐的数会陷入循环**
实际上和为1也算是循环，所以一个数快不快乐就看它循环里有没有1    
所以对应的，解法就是写一个while循环，用一个list记录出现过的数，先出现1就快乐，先出现list里的数（即陷入循环还没1）就不快乐

```python3
class Solution:
    def isHappy(self, n: int) -> bool:
        appeared=list()
        while n!=1:
            sum=0
            while n>0:
                sum+=(n%10)**2
                n=int(n/10)
            if sum not in appeared:  
                appeared.append(sum)
            else:
                return False
            n=sum
        return True
```
