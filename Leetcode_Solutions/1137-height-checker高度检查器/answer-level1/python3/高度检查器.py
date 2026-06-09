### 解题思路
非降序的意思就是一直是升序，所以先升序排列heights，再和heights对比，位置不一致的就是异常的。

### 代码

```python
class Solution(object):
    def heightChecker(self, heights):
        """
        :type heights: List[int]
        :rtype: int
        """
        desCount = 0

        # 方法1: 使用sorted升序排序后，手动比对每一个位置的值是否一致
        # sortedHeights = sorted(heights)
        # for i in range(len(heights)):
        #     if heights[i] != sortedHeights[i]:
        #         desCount += 1
        #     else:
        #         continue
        # return desCount

        # 方法2: 使用sorted升序排序后，利用enumerate加序号，比对每个位置的值是否一致
        for key,height in enumerate(sorted(heights)):
            if height != heights[key]:
                desCount += 1
        return desCount
         
        

```