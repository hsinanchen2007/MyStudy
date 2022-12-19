差点绕进去出不来了
```
class Solution:
    def distributeCandies(self, candies: int, num: int) -> List[int]:
        su = ((1 + num) * num) // 2
        index = 0
        while True:
            if candies < index * num * num + su:
                break
            else:
                candies = candies - index * num * num - su
                index += 1
        lis = [0] * num
        for i in range(num):
            if index != 0:
                lis[i] = num * (((index - 1) * index) // 2) + index * (i + 1)
            if candies > num * index + i + 1:
                lis[i] += num * index + i + 1
                candies -= num * index+ i + 1
            else:
                lis[i] += candies
                candies = 0
        return lis
```
