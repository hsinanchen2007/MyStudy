### 解题思路
1. 确定嵌套深度： 借鉴栈的思想，嵌套深度depth在遍历时是左括号时加1，是右括号时减1；
2. 嵌套的深度需要平均分配在A、B上才能保证A、B的深度最小，所以遍历时，当嵌套深度为偶数，分给A、赋值0，嵌套深度为奇数时，分给B赋值1.

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        depth = 0
        length = len(seq)
        answer = []
        for i in range(length):
            if seq[i] == "(":
                depth += 1
                answer.append(depth%2)
            else:
                answer.append(depth%2)
                depth -= 1
        return answer


```