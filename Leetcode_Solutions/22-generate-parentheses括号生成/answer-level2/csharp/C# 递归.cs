方法一：递归
```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        if(n == 0) return new List<string>();
        if(n == 1) return new List<string>(){ "()" };
        IList<string> list = GenerateParenthesis(n - 1);
        List<string> ans = new List<string>();
        foreach(string str in list)
        {
            for(int i = 0; i < str.Length; i++)
            {
                ans.Add(str.Insert(i, "()"));
            }
        }
        return ans.Distinct().ToList();
    }
}
```

方法二：穷举（可能超时）
```csharp
public class Solution {
    public IList<string> GenerateParenthesis(int n) {
        List<string> l1 = new List<string>() { "(" };
        List<string> l2 = new List<string>();
        bool useL1 = true;
        for (int i = 1; i < n * 2; i++)
        {
            List<string> s = useL1 ? l1 : l2;
            List<string> t = useL1 ? l2 : l1;
            foreach (string str in s)
            {
                t.Add(str + "(");
                t.Add(str + ")");
            }
            s.Clear();
            useL1 = !useL1;
        }
        List<string> source = useL1 ? l1 : l2;
        List<string> target = useL1 ? l2 : l1;
        foreach (string str in source)
        {
            if (IsValid(str))
            {
                target.Add(str);
            }
        }
        return target;
    }

    public bool IsValid(string str)
    {
        string temp = str;
        while (temp.Contains("()"))
        {
            temp = temp.Replace("()", string.Empty);
        }
        return temp.Length == 0;
    }
}
```