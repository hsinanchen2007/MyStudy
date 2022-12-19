### 解题思路
此题直接用连除法即可解决。

同题 [326. 3的幂](https://leetcode-cn.com/problems/power-of-three/solution/gelthin-chu-3-by-gelthin/)  
[231. 2的幂](https://leetcode-cn.com/problems/power-of-two/)


### 代码

```python3
class Solution:
    def isPowerOfFour(self, num: int) -> bool:
        if num <= 0:
            return False
        while num%4 == 0:
            num = num/4
        return num == 1
```