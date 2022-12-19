通过维持栈顶元素为整数来完成迭代器的Next操作。

```
public class NestedIterator {
    private Stack<NestedInteger> stack = new Stack<NestedInteger>();

    public NestedIterator(IList<NestedInteger> nestedList)
    {
        for (int i = nestedList.Count - 1; i >= 0; i--)
        {
            stack.Push(nestedList[i]);
        }
    }

    public bool HasNext()
    {
        // 如果栈顶是List就不断展开压栈，直到找到第一个Integer为止
        while (stack.Count > 0 && !stack.Peek().IsInteger())
        {
            var p = stack.Pop();
            for (int i = p.GetList().Count - 1; i >= 0; i--)
            {
                stack.Push(p.GetList()[i]);
            }
        }
        return stack.Count > 0 && stack.Peek().IsInteger();
    }

    public int Next()
    {
        return stack.Pop().GetInteger();
    }
}
```

