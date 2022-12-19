### 解题思路
利用counter初始化时保留元素出场顺序的特点，按照S优先处理即可

### 代码

```python3
class Solution:
    def customSortString(self, S: str, T: str) -> str:
        cs = collections.Counter(S)
        ct = collections.Counter(T)
        return ''.join(list((cs+ct-cs).elements()))
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)

