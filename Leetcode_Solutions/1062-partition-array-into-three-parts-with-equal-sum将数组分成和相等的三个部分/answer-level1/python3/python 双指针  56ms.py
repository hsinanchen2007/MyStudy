双指针法，sum1表示从第一个数组和，sum2表示第三个数组和，只要sum1 == sum2 == sum(A)//3，那么第二个数组也和也一样等于sum(A)//3，就返回True
```
def canThreePartsEqualSum(self, A: List[int]) -> bool:
        nums_sum = sum(A)       
        if not nums_sum % 3:
            return False
        sum_part = nums_sum // 3        #先求出数组和的三分之一
        sum1 = A[0]                     
        sum2 = A[-1]
        i = 0
        j = len(A) - 1
        while i + 1 < j:
            if sum1 == sum2 == sum_part:     # 只要sum1 == sum2 == sum(A)//3，那么就返回True
                return True
            elif sum1 == sum_part:           # 若sum1 == sum(A) // 3,那么i指针不变，减小j去使得sum2==sum(A)//3
                j -= 1
                sum2 += A[j]
            elif sum2 == sum_part:           # 同理如上
                i += 1
                sum1 += A[i]
            else:                            # 若sum1和sum2均不为 sum（A）//3，那么i增大， j减小
                i += 1
                j -= 1
                sum1 += A[i]
                sum2 += A[j]
        return False
```
