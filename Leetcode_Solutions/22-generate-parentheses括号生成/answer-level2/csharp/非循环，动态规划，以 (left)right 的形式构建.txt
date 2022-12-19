``` c#
public class Solution {
    Dictionary<int, IList<string>> Cache = new Dictionary<int, IList<string>> { { 0, new List<string> { "" } } };

        public IList<string> GenerateParenthesis(int n)
        {
            if (n == 0)
                return Cache[0];
            for (int i = 1; i <= n; i++)
            {
                var ans = new List<string>();
                for (int c = 0; c < i; c++)
                    foreach (var left in Cache[c])
                        foreach (var right in Cache[i - 1 - c])
                            ans.Add($"({left}){right}");
                Cache.Add(i, ans);
            }
            return Cache[n];
        }
}
```

