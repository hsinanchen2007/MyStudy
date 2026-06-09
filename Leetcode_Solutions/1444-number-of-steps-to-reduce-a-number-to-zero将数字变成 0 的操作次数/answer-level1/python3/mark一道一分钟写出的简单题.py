### 解题思路
这题比较简单了，只要按照题目描述，进行除或者减一操作，统计操作次数即可。

### 代码

```
class Solution:
    def numberOfSteps (self, num: int) -> int:
        loop = 0
        while num != 0:
            loop += 1
            if num % 2 == 0:
                num //= 2
            else:
                num -= 1
        
        return loop
```

![image.png](https://pic.leetcode-cn.com/adbf95fa2c4989f3a052f5b6cf932c8509e844861348df0a4d4cbd3254cd2712-image.png)
