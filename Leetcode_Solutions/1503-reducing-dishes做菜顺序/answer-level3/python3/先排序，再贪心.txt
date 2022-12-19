### 解题思路
![image.png](https://pic.leetcode-cn.com/b7ecb86b9d54a1f4074410d94fa6aedb9eee100b6e0735bdfd0086bcc8904e62-image.png)
先排序，大的放在最后。然后记两个数，s为当前的和，如果和为负数了，就不再叠加了。
re是满意程度。如果s大于0，则满意程度re = re + s（因为前面加入一个数，后面的序列都增加1，相当于将求和加一遍）

代码就简单多了，比起解释来方便太多
### 代码

```python3
class Solution:
    def maxSatisfaction(self, satisfaction: List[int]) -> int:
        satisfaction = sorted(satisfaction, reverse = True)
        re = 0
        s = 0
        for i, v in enumerate(satisfaction):
            s += v
            if s<0:
                break
            re += s
        return re

```