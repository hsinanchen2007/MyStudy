小白解法
**没什么特别的，代码很清楚了**
```
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0 for i in range(num_people)]
        x = 1
        while candies > 0:
            for i in range(num_people):
                if candies > x:
                    ans[i] += x
                    candies -= x
                    x += 1
                else:
                    ans[i] += candies
                    candies = 0
        return ans
```
![26BC8AB672124EE080111503914F77DF.png](https://pic.leetcode-cn.com/b6929e1f0ced6bf053aac2ae8d9db47064fab28d2c73a9217cd428bbcafa8109-26BC8AB672124EE080111503914F77DF.png)
