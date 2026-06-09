class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        sum = 0
        a = 0
        count = 0
        for i in range(len(A)):
            sum += A[i]
        if sum % 3 != 0:
            return False
        sum_small = sum/3
        for j in range(len(A)):
            a += A[j] #累加求和
            if a == sum_small:
                a = 0 #若累加和等于1/3的总和，则a重置为0
                count += 1 #计算1/3的总和出现了几组
        if count == 3:
            return True