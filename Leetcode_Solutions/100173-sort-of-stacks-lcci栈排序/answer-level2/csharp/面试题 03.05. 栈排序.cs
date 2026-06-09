### 解题思路
![image.png](https://pic.leetcode-cn.com/529da67fbe958ce42b1ee4bfec16117ffe99935e440640d0f3633b346e49bbb3-image.png)
核心思路是入栈时，将主栈的数字出栈暂存到临时栈，直到主栈为空或主栈的栈顶数字大于或等于要插入值，此时将插入值入主栈，然后将临时栈的数字按顺序放回到主栈；
改进思路：懒惰更新
临时栈存放的数据永远小于主栈的数据，每次新数字入栈时，仅仅动态调整两个栈，使临时栈的数据小于插入值，主栈的数据大于插入值，然后插入数值到主栈，每次Peek或Pop时才懒惰更新将临时栈的数据全部放回主栈。

### 代码

```csharp
public class SortedStack {
    Stack<int> stack = new Stack<int>();
    Stack<int> temp = new Stack<int>();

    public SortedStack()
    {
    }

    public void Push(int val)
    {
        /* 使用两个栈，stack 存储较大的值，temp用来临时存放较小的值
         * 调整两个栈，使临时栈的值小于插入值，主栈的值大于插入值，这样插入值才可以插入后依然有序
         */
        while (true)
        {
            var max = stack.Count == 0 ? int.MaxValue : stack.Peek();
            var min = temp.Count == 0 ? int.MinValue : temp.Peek();

            if (val > max)
            {
                temp.Push(stack.Pop());
            }
            else if (val < min)
            {
                stack.Push(temp.Pop());
            }
            else
            {
                // 此时调整好了
                break;
            }
        }

        // 往栈写入数据
        stack.Push(val);
    }

    public void Pop()
    {
        // 将临时栈内的数据返回已有栈
        while (temp.Count > 0)
        {
            stack.Push(temp.Pop());
        }

        if (stack.Count == 0)
        {
            return;
        }

        stack.Pop();
    }

    public int Peek()
    {
        // 将临时栈内的数据返回已有栈
        while (temp.Count > 0)
        {
            stack.Push(temp.Pop());
        }

        if (stack.Count == 0)
        {
            return -1;
        }

        return stack.Peek();
    }

    public bool IsEmpty()
    {
        return stack.Count == 0 && temp.Count == 0;
    }
}

/**
 * Your SortedStack object will be instantiated and called as such:
 * SortedStack obj = new SortedStack();
 * obj.Push(val);
 * obj.Pop();
 * int param_3 = obj.Peek();
 * bool param_4 = obj.IsEmpty();
 */
```