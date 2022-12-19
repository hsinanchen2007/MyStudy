```python
class Solution:
    def maxScoreSightseeingPair(self, A: List[int]) -> int:
        # score: A[i] + A[j] + i - j
        # the key is A[i] + A[j] + i - j => (A[i] + i) + (A[j] - j)
        # maximum(new_A[i] + newB[j]) (i != j)
        new_A, new_B = [], []
        for i, num in enumerate(A):
            new_A.append(num + i)
            new_B.append(num - i)
        return self.solve(new_A, new_B)

    def solve(self, A: List[int], B: List[int])-> int:
        # return max(A[i] + B[j]) and i < j
        # Time compleixty: O(N)
        # Space complexity: O(1)
        max_B = [0] * len(B)
        for i in range(len(B) - 1, -1, -1):
            if i == len(B) - 1: max_B[i] = B[i]
            else: max_B[i] = max(B[i], max_B[i + 1])
        
        ans, max_A = 0, float('-inf')
        for i in range(len(A) - 1):
            max_A = max(max_A, A[i])
            ans = max(ans, max_A + max_B[i + 1])
        return ans

```