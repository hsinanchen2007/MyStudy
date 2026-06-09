```
public static string[] BaseNumbers = Enumerable.Range(0, 10)
    .Select(number => number.ToString())
    .ToArray();

public static void PrintNumbers(int n)
{
    if (n == 0)
    {
        return;
    }

    // Skip(1) 避免出现 0 开头的数字
    foreach (var currentNumber in BaseNumbers.Skip(1))
    {
        PrintNumbersCore(currentNumber, n - 1);
    }
}

// 递归为当前数字后面追加基础数字
public static void PrintNumbersCore(string currentNumber, int n)
{
    Console.WriteLine(currentNumber);
    if (n == 0) return;

    foreach (var baseNumber in BaseNumbers)
    {
        PrintNumbersCore($"{currentNumber}{baseNumber}", n - 1);
    }
}
```