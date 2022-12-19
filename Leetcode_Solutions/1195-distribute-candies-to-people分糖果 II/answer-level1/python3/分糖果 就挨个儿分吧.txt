先想到什么方法就用什么方法吧

```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        arange = [0] * num_people
        if candies == 0:return arange

        start = 1
        while candies > 0:
            if candies < start:
                arange[(start-1) % num_people] += candies
                break
            arange[(start-1) % num_people] += start
            candies -= start
            start += 1     
        return arange
        
```
![image.png](https://pic.leetcode-cn.com/26018d247dccd2108f6eacf9061444df4ff55ac1c1b5dcaf0a5d793891f31409-image.png)
