显然是一个判断环的问题，那个快慢指针很好用
这里用dict存了已经算过的各个位数的平方和
```python
class Solution:
    def isHappy(self, n: int) -> bool:
        # 找环 -> 快慢指针
        squareDict = {}
        def findDightSquareSum(num):
            if num not in squareDict:
                ret = 0
                numCopy = num
                while num:
                    digit = num % 10
                    ret += digit ** 2
                    num //= 10
                squareDict[numCopy] = ret
            else:
                return squareDict[num]

        fast, slow = n, n
        while True:
            fast = findDightSquareSum(findDightSquareSum(fast))
            slow = findDightSquareSum(slow)
            # 找到环
            if fast == slow:
                break
        #如果是快乐数， 只会困在一个指向自己的1环内
        return fast == 1
```