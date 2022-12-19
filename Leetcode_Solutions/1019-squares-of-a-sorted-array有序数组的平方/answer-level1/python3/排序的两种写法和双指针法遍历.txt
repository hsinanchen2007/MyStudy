```
class Solution:
    def sortedSquares(self, A: List[int]) -> List[int]:
        # 1. most stupid approach comes into your mind first
        # return sorted([i*i for i in A]) # O(n*logN) with extra O(n) space
        
        # 2. as stupid as above
        # return [i*i for i in sorted(A, key=lambda x: abs(x))]
    
        # 3. transversing twice with two pointers, O(n) and O(n) extra space
        j, N = 0, len(A)
        while j < N and A[j] < 0:
            j += 1
        i = j - 1
        
        ans = []
        while i >= 0 and j < N:
            if A[i]**2 >= A[j]**2:
                ans.append(A[j]**2)
                j += 1
            else:
                ans.append(A[i]**2)
                i -= 1
        while i >= 0:
            ans.append(A[i]**2)
            i -= 1
        
        while j < N:
            ans.append(A[j]**2)
            j += 1
            
        return ans
```
