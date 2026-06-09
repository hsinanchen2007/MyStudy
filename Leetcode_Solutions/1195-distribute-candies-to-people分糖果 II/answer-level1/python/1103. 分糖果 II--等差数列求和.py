### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:
        ans = [0 for i in range(num_people)]
        num = int(0.5 * ((1+8*candies) ** 0.5 - 1))
        line = int(num // num_people)
        cow = num % num_people
        # print(num, line, cow)
        if cow != 0:
            for i in range(cow):
                ans[i] = int(line*(2*(i+1)+num_people*(line-1))/2 + (i+1) + line*num_people)
                # print(i, ans[i])
        ans[cow] = int(line*(2*(cow+1) + num_people*(line-1))/2 + candies - num*(num+1)/2)
        # print(cow, ans[cow])
        for i in range(cow+1,num_people):
            ans[i] = int(line*(2*(i+1) + num_people*(line-1))/2)
            # print(i, ans[i])
        return ans
```