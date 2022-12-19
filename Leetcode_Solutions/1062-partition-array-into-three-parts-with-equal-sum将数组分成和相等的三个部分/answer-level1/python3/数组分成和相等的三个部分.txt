### 解题思路
执行用时 :在所有 Python3 提交中击败了96.60%
内存消耗 :, 在所有 Python3 提交中击败了98.29%

1.首选算A的累加和能否被3整除，不可以那分不了3等分。
2.双指针前后向中间逼近，不用考虑中间那段怎么分，只要左右两段累加和等于3等分的数值，中间剩的那段也就找到了。
3.注意有两个坑：坑1:如果均值为0，head==0，此时要避免指针不往后移动
             坑2:头指针和尾指针不可相遇，此中真意为（中间一段不可为空）

### 代码

```python3
class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s %3 !=0:
            return False
        avg = s//3
        head = 0
        tail = 0
        i = 0
        j =len(A)-1
        res = False
        while i < j:
            if head != avg or avg == 0:
                head+=A[i]
                i+=1
            # if i == 0:
            #     break
            if tail != avg or avg == 0:
                tail+=A[j]
                j-=1
            if i==j+1:
                break
            if head == avg & tail == avg:
                res = True
                break
        return res
```