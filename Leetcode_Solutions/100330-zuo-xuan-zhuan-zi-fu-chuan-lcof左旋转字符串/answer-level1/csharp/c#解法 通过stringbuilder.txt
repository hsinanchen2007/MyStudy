```
    static StringBuilder Test(String s,int n)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append(s.Substring(n, s.Length-n));
            sb.Append(s.Substring(0, n));
            return sb.ToString();
        }
```
