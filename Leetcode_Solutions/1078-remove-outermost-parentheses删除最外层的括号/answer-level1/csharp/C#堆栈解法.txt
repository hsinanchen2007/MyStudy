```C# []
public string RemoveOuterParentheses(string S) {
            var stack = new Stack<int>();
            var sb = new StringBuilder();

            for (var i = 0; i < S.Length; i++)
            {
                int left = i;
                if (S[i] == '(')
                {
                    stack.Push(i);
                }
                else
                {
                    left = stack.Pop();
                }
                if (stack.Count == 0 && i - left - 1 > 0)
                {
                    sb.Append(S.Substring(left + 1, i - left - 1));
                }
            }

            return sb.ToString();
    }
```


