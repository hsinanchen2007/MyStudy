### 解题思路
还有一种数学思路：从0倒退回去，num等于多个2的次方的和，指数不连续。但是代码我没写:3

![image.png](https://pic.leetcode-cn.com/9e3313d5d5fb4b4d17f734607aca8c2ae91419823ab0d6ba8c1bea9a1d174db8-image.png)

![image.png](https://pic.leetcode-cn.com/278f8acd915e0ae0896154b133cac59bd434ebbffc9a3681bd58b2b396c1f1ae-image.png)




### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        count = 0
        while num != 0:
            count += 1
            if num % 2 == 0:
                num //= 2
            else:
                num -= 1
        return count
```