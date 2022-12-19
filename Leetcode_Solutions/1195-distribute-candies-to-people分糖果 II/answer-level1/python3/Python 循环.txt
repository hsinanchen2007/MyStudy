### 解题思路
无脑循环，求更优解

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        init_candies = [0 for _ in range(num_people)]
        times = 0
        pos = 1
        while candies > (pos + num_people * times):
            
            send_candies = pos + num_people * times
            init_candies[pos - 1] += send_candies
            pos += 1
            candies -= send_candies

            # 糖果分到人的尽头了
            if pos > num_people:
                times += 1
                pos = 1

        # 剩余不够的全部给下一个人
        if candies:
            init_candies[pos - 1] += candies
        return init_candies


```