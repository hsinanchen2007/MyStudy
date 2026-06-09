### 解题思路
此处撰写解题思路利用Counter统计特性和支持减操作，然后求出异位个数的和

### 执行结果
![image.png](https://pic.leetcode-cn.com/c67a130b1899ec6d2d6cd271acd7b3b1c6c508ba5961f42bf04b9d0e17f9c749-image.png)

### 代码

```python3
class Solution:
    def minSteps(self, s: str, t: str) -> int:
        return sum((collections.Counter(s) - collections.Counter(t)).values())
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)
