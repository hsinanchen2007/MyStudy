class Solution:
    def canPlaceFlowers(self, flowerbed: List[int], n: int) -> bool:
        l = len(flowerbed)
        if l < 2: 
            return n == 0 or flowerbed[0] == 0 == n-1 # 特殊情况判定，花圃数组不为空
        count = 1
        for i in range(1, l):
            if flowerbed[i-1] == flowerbed[i]:
                count += 1
            else:
                n -= (count // 2)
                count = 0
        n -= (count+1) // 2
        return n <= 0