### 解题思路
模拟分糖过程

### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        # 初始化
        ans = [0] * num_people
        t = 1
        # 如果还有剩余糖果
        while candies > 0:
            # 循环所有人
            for i in range(num_people):
                # 剩余糖果数量 >= 本次需要分的糖果数量
                if candies - t >= 0:
                    candies -= t
                    ans[i] += t
                    # 下一次分糖果数量+1
                    t += 1
                # 剩余糖果数量不足本次需要分的糖果数量
                else:
                    # 将剩余糖果全部分出
                    ans[i] += candies
                    candies = 0
                    # 糖果已分完，不需要继续循环后续人员，直接跳出
                    break
        return ans
```