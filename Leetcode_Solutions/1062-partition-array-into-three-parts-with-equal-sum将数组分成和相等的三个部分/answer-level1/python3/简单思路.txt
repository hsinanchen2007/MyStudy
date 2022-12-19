### 解题思路

![1.PNG](https://pic.leetcode-cn.com/c3d4cd08ab1fcf50388e0dffac8cfac8a8c47834aa13fc3f5c41febd577f0519-1.PNG)
1.先算整个数组的和，若不能被3整除，直接返回false
2.若可以被3整除，用总和除以3得到每部分的和partsum。遍历数组，用count记录和为partsum的部分。找到一个和为partsum的部分，count+1.若count为2，证明已将数组分为两部分，看数组是否已经到头，若未到头说明最后一部分不为空，返回True。其余情况返回False
### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        total = sum(A)
        if total%3!=0:
            return False
        partsum = total//3
        part = 0
        count = 0
        for i in range(len(A)):
            part += A[i]
            if part==partsum:
                count += 1
                part = 0
                if count==2 and i<len(A)-1:
                    return True
        return False

            
            

```