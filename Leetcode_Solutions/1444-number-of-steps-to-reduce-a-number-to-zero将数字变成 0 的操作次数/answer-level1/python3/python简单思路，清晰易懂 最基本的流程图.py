### 解题思路
数学流程图最简单的，这个流程图很好想出来，想出来立马会想到循环+判断
用一个初始变量计算步骤就欧克了！
思路是非常简单清晰的，我这个很容易看懂

![TIM截图20200408122801 (2).png](https://pic.leetcode-cn.com/a2983fc118b33fbbf73fdf6670c7be9c436359c515edaca7b24d401c02889312-TIM%E6%88%AA%E5%9B%BE20200408122801%20\(2\).png)

### 代码

```python3
class Solution:
    def numberOfSteps (self, num: int) -> int:
        n = 0
        while num>0:
            if num == 0:
                return n
            elif num%2 ==0:
                num = num/2
                n += 1
            else:
                num = num-1
                n += 1
        return n
```