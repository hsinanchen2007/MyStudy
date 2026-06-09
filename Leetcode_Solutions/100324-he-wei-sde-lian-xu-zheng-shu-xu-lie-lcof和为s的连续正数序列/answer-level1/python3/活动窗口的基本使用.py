### 解题思路
本题有一个非常重要的前提条件：连续正整数————这就意味着3+6=9这种跳跃的情况是不存在的，因此就采用滑动窗口的办法粗暴求解即可。

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        i = 1
        j = 1
        sum = 0
        res = []

        while i <= target//2:
            if sum < target:
               
                sum += j
                j += 1
            elif sum > target:
                
                sum -= i
                i += 1
            else:
                arr = list(range(i,j))
                res.append(arr)
                sum -= i
                i +=1

        return res


```