![屏幕快照 2019-11-28 下午9.45.58.png](https://pic.leetcode-cn.com/6a2819b49b4c9a0a0adc2aa328d6886cb79683fa51c35cd0e618ad67c27b0f51-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-11-28%20%E4%B8%8B%E5%8D%889.45.58.png)

class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        return len(heights)-list(map(lambda x:x[0]-x[1],zip(sorted(heights),heights))).count(0)