执行用时 :36 ms, 在所有 python3 提交中击败了99.84%的用户
内存消耗 :12.7 MB, 在所有 python3 提交中击败了100.00%的用户

题目很好理解，就是根据四种情况，分别做出一些行动。
由于题干里较为明确地表示得分与最后1~2轮有效得分有关，因此很容易联想到用栈的方式去做。

一开始用数组来实现**顺序栈**（`stack = []`），得分不高，因为数组的插入和删除的复杂度为O(n)。换成**链式栈**（`stack = collections.deque([])`）后，效果瞬间好得出奇，因为链表的插入和删除的复杂度为O(1)。

python的`collections.deque`对象是以双向链表实现的，在很多题目里都有奇效~。

```
class Solution:
    def calPoints(self, ops:list) -> int:
        stack = collections.deque([])
        result = 0
        for v in ops:
            if v == 'C':
                result -= stack.pop()
                continue
            elif v == 'D':
                value = 2 * stack[-1]
            elif v == '+':
                value = stack[-1] + stack[-2]
            else:
                value = int(v)
            stack.append(value)
            result += value
        return result
```
