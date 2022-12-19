### 解题思路
这题没用什么算法, 就只是把题意翻译一下而已.
每次给一个孩子发的糖果数目 = num_people * k + i + 1
其中k是第几轮, i是第几个孩子.

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        L = [0,] * num_people
        count = 0
        flag = True
        k = 0  # 第几轮
        while flag:
            for i in range(num_people):  # 遍历所有孩子
                add_val = num_people * k + i + 1               
                if add_val + count > candies:
                    add_val = candies - count
                    flag = False
                L[i] += add_val
                count += add_val
                if not flag:
                    break
            k += 1
        return L
```