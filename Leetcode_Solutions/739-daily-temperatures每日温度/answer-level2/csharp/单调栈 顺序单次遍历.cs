```
public int[] DailyTemperatures(int[] T)
{
    // 记录最短升温的等待天数
    var result = new int[T.Length];
    // 维护一个单调递减栈，保存的是下标用于计算相差的天数
    var descTIndexStack = new Stack<int>();
    for (int i = 0; i < T.Length; i++)
    {
        // 栈中所有比当前温度低的天数最短等待天数就是索引差值，因为中间的温度都更低（递减栈）
        while (descTIndexStack.Count > 0 && T[descTIndexStack.Peek()] < T[i])
        {
            result[descTIndexStack.Peek()] = i - descTIndexStack.Pop();
        }
        descTIndexStack.Push(i);
    }
    return result;
}
```
