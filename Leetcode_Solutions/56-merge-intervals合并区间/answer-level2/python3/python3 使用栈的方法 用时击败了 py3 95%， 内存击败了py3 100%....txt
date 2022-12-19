### 解题思路
其实就是先排序一下， 用一个类似栈的方法。每次比较栈顶元素和即将入栈元素。
如果栈顶元素的结尾 >= 入栈元素的开头，就意味着区间重叠。那么重写栈顶元素。 注意新的栈顶元素的结尾是 原栈顶元素的结尾以及新入栈元素结尾， 二者之中选大......

**话说python 的sort真的很流氓......**

### 代码

```python3
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals = sorted(intervals)
        ans = []
        for el in intervals:
            if not ans:
                ans.append(el)
            else:
                prev = ans[-1]
                if prev[1] >= el[0]:
                    ans[-1] = [prev[0], max(prev[1], el[1])]
                else:
                    ans.append(el)
        return ans
```