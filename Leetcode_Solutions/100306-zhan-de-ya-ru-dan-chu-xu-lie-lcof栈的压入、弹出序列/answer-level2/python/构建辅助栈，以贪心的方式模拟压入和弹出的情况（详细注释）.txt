### 解题思路
构建辅助栈，以贪心的方式模拟压入和弹出的情况

### 代码

```python3
class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        """
        构建辅助栈，以贪心的方式模拟压入和弹出的情况
        """
        if pushed is None or popped is None:
            return False
        if len(pushed) != len(popped):
            return False

        # popped 中 待检测栈顶元素 索引
        # 每个 待检测栈顶元素 都是对应 合法栈（如果 popped 顺序是正确的，必然存在一 顺序压入的合法栈 与其对应）的栈顶元素
        popped_index = 0

        # 辅助栈，保存还未到 弹出时机 的元素
        # 如果当前 待检测栈顶元素 与 pushed 中要压入的元素不一致
        # 那么就意味着现在不是这个 要压入元素 的弹出时机，所以我们就将其先压入 辅助栈
        auxiliary_stack = []

        # 遍历所有压入元素
        for n in pushed:
            # 如果当前 压入元素 与 待检测弹出元素 相同
            # 那么表示 该压入元素 在压入入栈后可以立即弹出
            # 因此当前 待检测演出元素 有效，我们将索引指向下一个 待检测栈顶元素
            if n == popped[popped_index]:
                popped_index += 1

                # 待检测栈顶元素更新了，我们 总是尝试清空 辅助栈（贪心）
                while auxiliary_stack:
                    # 如果 辅助栈栈顶元素 与 待检测栈顶元素 相同
                    # 就意味着现在是该 辅助栈栈顶元素 的弹出时机
                    if auxiliary_stack[-1] == popped[popped_index]:
                        auxiliary_stack.pop()
                        popped_index += 1
                    else:
                        break

            # 压入元素 与 待检测栈顶元素 不同，那么就意味着还不到 压入元素的弹出时机
            # 那么我们先将其压入辅助栈
            else:
                auxiliary_stack.append(n)

        # 所有元素通过检测
        return popped_index == len(popped)

```