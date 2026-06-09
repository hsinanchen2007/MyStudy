### 解题思路
这道题可以直接用数学方法算出一共有几轮，因为每一轮需要的糖果数是等差数列求和，而r轮需要的糖果数同样是等差数列求和，只需要令r轮需要的糖果数<=candies，求r即可求得完整的轮数，剩下的只需要遍历不到一轮就行。


### 代码

```python
class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        res = [0] * num_people
        num = 1
        ind = 0
        while True:
            if num <= candies:
                res[ind] += num
                candies -= num
                num += 1
                ind = (ind + 1) % num_people
            else:
                res[ind] += candies
                break
        return res
```