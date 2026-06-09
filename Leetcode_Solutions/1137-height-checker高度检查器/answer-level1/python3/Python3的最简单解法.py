# 超过好多Python3用户。。。
```
class Solution:
    def heightChecker(self, heights: List[int]) -> int:
        res = sorted(heights)
        count = 0
        for i in range(len(heights)):
            if res[i] != heights[i]:
                count += 1
        return count
```
![QQ图片20190707175402.png](https://pic.leetcode-cn.com/6817031a3b3efb62a6904cba76ae4b706bd4495f2b20df1a14393bdd232fac70-QQ%E5%9B%BE%E7%89%8720190707175402.png)

