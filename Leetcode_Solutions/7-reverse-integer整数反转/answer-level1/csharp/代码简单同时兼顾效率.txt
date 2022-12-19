
**代码：**

这道题的最优解已经有很多了，我只能在代码方面去花里胡哨地改动了。

自我感觉良好（下面的代码才是我所能想到的最简单）：

```csharp []
public int Reverse(int x)
{
    if (x < 0)
    {
        int.TryParse(new string((-x).ToString().Reverse().ToArray()), out x);
        return -x;
    }
    else
    {
        int.TryParse(new string(x.ToString().Reverse().ToArray()), out x);
        return x;
    }
}
```

放弃一丁点效率：

```csharp []
public int Reverse(int x)
{
    int.TryParse(x < 0 ? "-" + new string((-x).ToString().Reverse().ToArray()) : new string(x.ToString().Reverse().ToArray()), out x);
    return x;
}
```

其实两种解决方案差不多，但我觉得第一种效率应该更高点。毕竟少了一个字符串的拼接。
