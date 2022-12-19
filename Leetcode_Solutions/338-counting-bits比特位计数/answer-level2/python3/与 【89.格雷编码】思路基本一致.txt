### 解题思路
可以使用与[89.格雷编码](https://leetcode-cn.com/problems/gray-code/solution/)基本一致的思路来解决。我们知道，在格雷编码中，当增加新的格雷编码时，我们可以逆序遍历已经生成的格雷编码并在其二进制数字最高位左边添加数字‘1’。而本题恰与格雷编码相反，我们以正序遍历已经计算完1的个数的数字，并在其统计结果上加1，如下图。

![图片 1.png](https://pic.leetcode-cn.com/5efae0d142e244da63435eae5341534dcfc2e481748e028a687ac0bc78088639-%E5%9B%BE%E7%89%87%201.png)



### 代码

```python3
class Solution:
    def countBits(self, num: int) -> List[int]:
        idx,res = 0, []
        res.append(0)

        while idx <= num:
            length = len(res)
            for i in range(length):
                res.append(res[i]+1)
                idx += 1

        return res[:num+1]
```
时间复杂度度与空间复杂度都是$2^{(\lceil log_{2}N \rceil)}$