### 解题思路
1. 解题目标：
- 数组分成三个区间a,b,c
- 每个区间不重叠
- 每个区间的和相同
2. 解题思路：
- 1 两层遍历，判断a==b和a+2b=sum(A)，时间复杂度过高
- 2 将第二层的遍历简化，先还原a=0，利用count计数

### 代码

```python3
'''
解题目标：
数组分成三个区间a,b,c
每个区间不重叠
每个区间的和相同
解题思路：
1 两层遍历，判断a==b和a+2b=sum(A)，时间复杂度过高
2 将第二层的遍历简化，先还原a=0，利用count计数
'''
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum_a = sum(A)
        if sum_a % 3 != 0:return False
        n = len(A)
        area_sum = sum_a // 3
        count = 0
        a = 0
        #最后一个区间至少有一个元素
        for i in range(n-1):
            a += A[i]
            if a == area_sum:
                count += 1
                if count == 2:
                    return True
                a = 0
        return False







```