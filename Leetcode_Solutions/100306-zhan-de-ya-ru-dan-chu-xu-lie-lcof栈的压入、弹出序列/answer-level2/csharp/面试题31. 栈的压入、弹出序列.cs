### 解题思路
C# 队列x2+栈 模拟

### 代码

```csharp
public class Solution {
    public bool ValidateStackSequences(int[] pushed, int[] popped) {
        if (pushed.Length != popped.Length) return false;
        // 两个数组转换为队列
        var pushQueue = new Queue<int>(pushed);
        var popQueue = new Queue<int>(popped);
        // 模拟真实的栈
        var stack = new Stack<int>();
        // 遍历出栈队列
        while (popQueue.Count > 0)
        {
            var nextPop = popQueue.Dequeue();
            // 优先在真实栈顶查找要出栈的数
            if (stack.Count > 0 && stack.Peek() == nextPop)
            {
                stack.Pop();
                // 出栈成功
                continue;
            }

            // 栈顶不是要出栈的数，如果入栈队列为空，返回 False
            if (pushQueue.Count == 0) return false;
            // 继续查找入栈队列，直到找到要出栈的数或入栈队列为空
            while (pushQueue.Count > 0)
            {
                var nextPush = pushQueue.Dequeue();
                if (nextPush == nextPop)
                {
                    break;
                }
                // 不是要出栈的数，就入栈
                stack.Push(nextPush);
            }
        }
        return true;
    }
}
```