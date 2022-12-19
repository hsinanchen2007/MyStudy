
从上面大神的题解中了解到，一个自然数最多用4个完全平方数相加可以得到。所以我的代码会依次判断，答案是否为1，是否为2，是否为3，都不是的话那就为4

1. 首先把小于`n`的所有完全平方数找到，放入`ones`中。这时候如果发现`n`也是完全平方数，返回1
2. 通过`ones`中任取2个数相加（可以重复），得到所有小于`n`且最少由2个平方数相加可以得到的数，放入`twos`这个`hashset`中。过程中如果发现`n`也可以由2个平方数相加得到，返回2
3. 遍历`ones`所存放的完全平方数，如果用`n`减掉该数，存在于`twos`中，则说明`n`可以由3个平方数相加，返回3
4. 以上都不满足，返回4

```
class Solution:
    def numSquares(self, n: int) -> int:
        ones = []
        num = 1
        square = num**2
        while square < n:
            ones.append(square)
            num += 1
            square = num**2
        if square == n:
            return 1
        
        twos = set()       
        countOne = len(ones)
        for i in range(countOne):
            if 2*ones[i] > n:
                break
            for j in range(i, countOne):
                twoSum = ones[i] + ones[j]
                if twoSum >= n:
                    break
                twos.add(twoSum)
            if twoSum == n:
                return 2
        
        for one in ones:
            if n - one in twos:
                return 3
        
        return 4
```
