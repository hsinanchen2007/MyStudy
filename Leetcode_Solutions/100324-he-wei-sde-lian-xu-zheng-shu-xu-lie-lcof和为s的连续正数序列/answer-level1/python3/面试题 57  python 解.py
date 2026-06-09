### 解题思路
法一：时间复杂度O(n²),空间复杂度(n²),好慢....

法二：利用数据求和公式来做，好快,时间复杂度O(n),空间复杂度O(n)
### 代码

```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i = 1
        # 总列表和
        result = []
        flag = True
        while flag:
            temp =[]
            sums = 0
            if i == target//2 + 1:
                break
            for m in range(i,target//2+2):
                sums += m
                if sums < target:
                    temp.append(m)
                elif sums == target:
                    temp.append(m)
                    result.append(temp)
                    i += 1
                    break
                else:
                    i += 1
                    break;
        return result

```

```python
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        #求和公式 Sn = a1*n +n*(n-1)//2
        #反解的到 a1 = (Sn - n(n-1)//2)//n
        #其中a1为第一项，n为项数，Sn为target
        result = []
        # 题目要求至少有2个数
        for i in range(2,target):
            #i为项数
            a1 = (target - i*(i-1)//2)
            if a1 <= 0:
                break
            if a1%i == 0:
                result.insert(0,[m for m in range(a1//i,a1//i+i)])
        return result
```