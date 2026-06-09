```C# []
public string RemoveOuterParentheses(string S) {
       var sb = new StringBuilder();
            int left = -1;
            int num = 0;
            for (var i = 0; i < S.Length; i++)
            {
                if (S[i] == '(')
                {
                    num++;
                }
                else
                {
                    num--;
                }
                if (num == 0)
                {
                    if (i - left - 1 > 0)
                    {
                        sb.Append(S.Substring(left + 1, i - left - 1));
                    }
                    left = -1;
                }
                else if (num == 1 && left == -1)
                {
                    left = i;
                }
            }
            return sb.ToString(); 
    }
```

