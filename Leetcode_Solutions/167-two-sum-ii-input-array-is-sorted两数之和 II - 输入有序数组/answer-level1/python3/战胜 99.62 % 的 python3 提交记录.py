![image.png](https://pic.leetcode-cn.com/ca1495250cc41905994e7ab986c090cf7a708e1d681fe539092dd0800780200b-image.png)

```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        d = {}
        for i in range(len(numbers)):
            try:
                return [d[target - numbers[i]], i+1]
            except:
                d[numbers[i]] = i+1
```
- 时间复杂度：O(n)
- 空间复杂度:O(n)