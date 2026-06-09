
![屏幕快照 2019-12-22 下午10.01.00.png](https://pic.leetcode-cn.com/b4f98b54c82e718af103a642fee19022af2d925c87c9d7b8c44510702ffd3c99-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-12-22%20%E4%B8%8B%E5%8D%8810.01.00.png)


参考官方解答



```python
class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        length = len(ratings)

        lastCandy  = 1
        candyCount = 1
        downIndex  = 0
        inDownHill = False

        for i in range(1, length):
            if ratings[i] >= ratings[i-1]:
                # 上升段
                if inDownHill:
                    # 处理拐点：前一个rating值为局部最小，
                    # 则前一个candy需要调整为1,当前即为2,
                    # 再对前一个下降段做多退少补
                    candy = 2

                    n = i - downIndex
                    if lastCandy >= 1: n -= 1
                    candyCount += (1- lastCandy) * n
                else:
                    candy = lastCandy + 1

                # 与前一个相等时，令当前值为1, 贪心思想
                if ratings[i] == ratings[i-1]: candy = 1

                downIndex  = i
                inDownHill = False
            else:
                # 下降段
                candy = lastCandy - 1
                inDownHill = True

            lastCandy   = candy
            candyCount += lastCandy

        # 如果最后一段是下降段,仍需要处理多退少补
        if inDownHill:
            n = length - downIndex
            if lastCandy >= 1: n -= 1
            candyCount += (1 - lastCandy) * n

        return candyCount
```