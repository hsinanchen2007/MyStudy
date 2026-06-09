![深度截图_选择区域_20200213224528.png](https://pic.leetcode-cn.com/ac05602130285a1d94ce574bc01b73be13a9b4322d0d743d4d7e66a1e2e219c4-%E6%B7%B1%E5%BA%A6%E6%88%AA%E5%9B%BE_%E9%80%89%E6%8B%A9%E5%8C%BA%E5%9F%9F_20200213224528.png)
### 解题思路

collections.Counter 统计每个数字的数量

通过 Counter.items 方法转换成数组

按数字数量多少排序（sorted 方法）

返回数量最多的一个数字

### 代码

```python
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:
        return sorted(list(__import__('collections').Counter(nums).items()), key=lambda x:x[1])[-1][0]
```