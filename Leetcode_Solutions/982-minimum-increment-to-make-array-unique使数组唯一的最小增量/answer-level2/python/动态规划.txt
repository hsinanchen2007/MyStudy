先排序，再从左到右一个一个调整
def minIncrementForUnique(self, A):

        A.sort()
        le = len(A)
        B = []
        ans = 0
        for i in range(1,le):
            B.append(A[i]-A[i-1]-1)
        B.append(0)
        for i in range (0,le-1):
            if B[i]<0:
                ans -= B[i]
                B[i+1] += B[i]
        return ans