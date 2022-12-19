class Solution:
    def canThreePartsEqualSum(self, A):
        size=len(A)
        if size<3:
            return False
        asum=0
        for i in range(size):
            asum+=A[i]
        if asum%3 !=0:
            return False
        threeSum=asum/3
        beginSum=A[0]
        endSum=A[size-1]
        beginNum=1
        endNum=1
        for i in range(1,size):
            if beginSum !=threeSum:
                beginNum+=1
                beginSum+=A[i]
            if endSum !=threeSum:
                endNum+=1
                endSum+=A[size-1-i]
            if beginNum+endNum>=size:
                return False
            if beginSum==threeSum and endSum==threeSum:
                return True
        return False