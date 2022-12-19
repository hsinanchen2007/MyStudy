其实就是解析一个数组套数组字符串，间隔的数组抓取出来实例化成 `NestedInteger` 。每次将处理的`[]` 内的数据放到 stack 的末尾做处理，当当前 `[]` 处理完毕后，弹栈并更新弹栈后的栈顶。注意的点是：

1. 坑爹数据额是 `[[]]` 这种嵌套空数组；
2. 末尾边界的处理，即遇到 `]` 和 `,` 的情况要考虑清楚；
3. 只有数字的情况要用 `NestedInteger(value=n)` 构造；

错了好多次，调试了半个多小时才做出来，难受。模拟题是我的杀手。。

```python
class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        if s[0] != '[': 
            return NestedInteger(value=int(s))
        
        res, st = [], 0
        if s == '[]':
            return NestedInteger()
        
        for i, c in enumerate(s):
            if c == '[':
                res.append(NestedInteger())
                st = i + 1
            elif c == ',' or c == ']':
                if i > st: 
                    sn = s[st: i]
                    if len(sn) > 0:
                        res[-1].add(NestedInteger(int(sn)))
                st = i + 1    
                # res 大于1
                if c == ']' and len(res) > 1:
                    tmp = res.pop()
                    res[-1].add(tmp)
        return res[-1]
```
