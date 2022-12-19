class Solution:
    def trap(self, height: List[int]) -> int:
        n = len(height)
        if n <= 2:
            return 0
        i = 0
        j = 1
        result = 0
        while j < n:
            if height[j]< height[i]:
                j += 1
            else:
                count = 0
                for num in range(i,j):
                    count += height[i]-height[num]
                result += count
                i = j
                j += 1
        j = n-2
        k = n-1
        while j >= i:
            if height[j] < height[k]:
                j -= 1
            else:
                count = 0
                for num in range(k,j,-1):
                    count += height[k]-height[num]
                result += count
                k = j
                j -= 1
        return result

