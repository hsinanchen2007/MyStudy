### 解题思路

1. 如何保证划分后，嵌套深度最小？
    1. 对括号进行嵌套层数记录
    2. 奇数层括号分到一组，偶数层括号分到另一组
2. 如何计算每个括号对应的嵌套深度？
    1. 利用栈的思想：遇到左括号，（入栈），嵌套深度+1
    2. 遇到右括号，计算完分组下标后，（出栈），嵌套深度-1。
3. 编程思想：
    1. 变量初始化：当前括号嵌套深度depth,最终的分组下标mindex
    2. 遍历括号字符串：
        1. 遇到左括号：深度depth+1，根据当前括号“嵌套深度”的奇偶性，确定分组下标并记录；
        2. 遇到右括号：根据当前括号“嵌套深度”的奇偶性，确定分组下标并记录，深度-1；
    2. 返回分组下标mindex
4. 关于性能优化：
    1. mindex记录分组下标时，用索引比append要快
    2. 判断嵌套深度的奇偶时，depth%2可直接代替depth%2==1
### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        depth = 0
        mindex = [0]*len(seq)
        for i in range(len(seq)):
            if seq[i] == "(":
                depth += 1
                mindex[i]= 0 if depth%2 else 1
            else:
                mindex[i]= 0 if depth%2 else 1
                depth -= 1
        return mindex
```