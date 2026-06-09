### 解题思路
- 利用counter计数器保留出场顺序的特性进行计数
- 对计数后结果筛选出个数为1的列表
- 放置列表为空，令其与空格字符串相加
- 返回第1个即可，此时若原字符串有满足计数为1的则返回第一个，否则返回空字符串

### 结果
![image.png](https://pic.leetcode-cn.com/1c6d98e15ad21236487d973d858070a03b7bb6cd71cf36b818354d66f2c70498-image.png)

### 代码

```python3
class Solution:
    def firstUniqChar(self, s: str) -> str:
        return ([k for k, v in collections.Counter(s).items() if v==1]+[' '])[0]
```
最后，低调推荐个人公众号：[小数志](https://pic.leetcode-cn.com/962ebbb357f15acd99bfcc5dc74188fc9f2a3492e73bca90b673428d5c1c7559-image.png)