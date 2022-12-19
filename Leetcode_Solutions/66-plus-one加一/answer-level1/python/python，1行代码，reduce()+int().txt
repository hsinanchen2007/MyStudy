### 思路
既然是数字加1，那就转换成数字再转回来就行了

### 代码
```python
class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        from functools import reduce
        return [int(num) for num in str(reduce(lambda x, y:x*10+y, digits)+1)]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)