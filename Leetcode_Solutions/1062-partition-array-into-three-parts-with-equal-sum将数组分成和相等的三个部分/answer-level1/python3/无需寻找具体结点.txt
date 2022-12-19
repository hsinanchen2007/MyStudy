### 解题思路
题目只需要找到能划分为三个和相等的非空即可，可以认为前两部分都等于平均值，则第三部分就一定等于平均值。因此，我求出平均值后，对数组按顺序求和，只要有和达到平均值一次，就清空sum,重新计算，且flag值+1.最后，只要得到flag值大于2，则表示可以划分为3个和相等的非空部分。

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        flag = 0
        sumList = sum(A)
        meanList = sumList // 3
        groupsum = 0

        if(sumList % 3 != 0):
            return False

        for num in A:
            groupsum += num
            if(groupsum == meanList):
                groupsum = 0
                flag += 1
        
        if(flag > 2): 
            return True 
        else:
            return False
              
```