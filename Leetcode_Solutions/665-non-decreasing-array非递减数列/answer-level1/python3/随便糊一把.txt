### 解题思路

简单的题目也交了好多次才对，主要是要判断一下递减的交叉位置（n+2与n、n+1与n-1）的大小关系，若全为递减则不是一次调整可以使题设条件成立的，可以直接返回False，否则就加一次调整次数，下次再有直接返回False。

![image.png](https://pic.leetcode-cn.com/fdef53537236fabd55813f66ba7d63f4be84f9c105245f3599ab3f37300c8077-image.png)

### 代码

```python3
class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        t = 0
        l = len(nums)
        for n in range(l-1):
            if n >= 1:
                n_l = nums[n-1]
            else:
                n_l = 0
            if n <= l-3:
                n_r = nums[n+2]
            else:
                n_r = 10001
            if nums[n+1] < nums[n]:
                if t == 1:
                    return False
                if nums[n+1] <= n_l and n_r <= nums[n]:
                    return False
                t += 1
        return True
```