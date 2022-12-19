### 解题思路
构造一个列表用于记录每个数中1的个数，然后逐级翻倍求解，其中下一倍区间的每个数中1的个数是前面对应位置个数+1，直至达到目标长度，输出

### 结果
![image.png](https://pic.leetcode-cn.com/7ec71565e87996d8f04d0ae178d9d7c128d67703fab942aa1a1167bc9f684cb5-image.png)


### 代码

```python3
class Solution:
    def countBits(self, num: int) -> List[int]:
        nums, length= [0,1], 2
        while length <= num:
            nums.extend([1+n for n in nums])
            length *= 2
        return nums[:num+1]
```