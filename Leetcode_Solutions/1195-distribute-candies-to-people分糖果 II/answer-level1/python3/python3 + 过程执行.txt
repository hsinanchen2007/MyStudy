执行用时 :44 ms, 在所有 Python3 提交中击败了98.47%的用户

内存消耗 :13.9 MB, 在所有 Python3 提交中击败了100.00%的用户

```
class Solution:
    def distributeCandies(self, candies, num_people):
        result = [0] * num_people
        current_num = 1
        while candies > 0:
            for i in range(num_people):
                if candies >= current_num:
                    result[i] += current_num
                    candies -= current_num
                    current_num += 1
                else:
                    result[i] += candies
                    candies -= candies
                    break
        return result
```
