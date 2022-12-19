#### 方法一： 贪心

**思路**

所有的元素一定是按顺序 `push` 进去的，重要的是怎么 `pop` 出来？

假设当前栈顶元素值为 `2`，同时对应的 `popped` 序列中下一个要 `pop` 的值也为 `2`，那就必须立刻把这个值 `pop` 出来。因为之后的 `push` 都会让栈顶元素变成不同于 `2` 的其他值，这样再 `pop` 出来的数 `popped` 序列就不对应了。

**算法**

将 `pushed` 队列中的每个数都 `push` 到栈中，同时检查这个数是不是 `popped` 序列中下一个要 `pop` 的值，如果是就把它 `pop` 出来。

最后，检查不是所有的该 `pop` 出来的值都是 `pop` 出来了。

```java [solution1-Java]
class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        int N = pushed.length;
        Stack<Integer> stack = new Stack();

        int j = 0;
        for (int x: pushed) {
            stack.push(x);
            while (!stack.isEmpty() && j < N && stack.peek() == popped[j]) {
                stack.pop();
                j++;
            }
        }

        return j == N;
    }
}
```

```python [solution1-Python]
class Solution(object):
    def validateStackSequences(self, pushed, popped):
        j = 0
        stack = []
        for x in pushed:
            stack.append(x)
            while stack and j < len(popped) and stack[-1] == popped[j]:
                stack.pop()
                j += 1

        return j == len(popped)
```


**算法复杂度**

* 时间复杂度：$O(N)$，其中 $N$ 是 `pushed` 序列和 `popped` 序列的长度。

* 空间复杂度：$O(N)$。