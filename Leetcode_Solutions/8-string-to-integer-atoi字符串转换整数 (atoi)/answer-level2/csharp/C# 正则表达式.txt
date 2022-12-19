```csharp
public int MyAtoi(string str) {
    if(string.IsNullOrEmpty(str))
    {
        return 0;
    }
    System.Text.RegularExpressions.Regex reg = new System.Text.RegularExpressions.Regex(@"^[+-]?\d+");
    str = reg.Match(str.TrimStart()).Value;
    if(string.IsNullOrEmpty(str))
    {
        return 0;
    }
    int ans = 0;
    if(int.TryParse(str, out ans))
    {
        return ans;
    }
    if(str[0].Equals('-') && str.Length > 1)
    {
        return int.MinValue;
    }
    else
    {
        return int.MaxValue;
    }
}
```