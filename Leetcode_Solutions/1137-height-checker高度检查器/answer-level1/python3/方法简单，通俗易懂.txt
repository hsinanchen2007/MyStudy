class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        heights1 = sorted(heights)
        # return heights1
        counts = 0
        for i in range(len(heights)):
            if heights1[i] != heights[i]:
                counts += 1
        return counts