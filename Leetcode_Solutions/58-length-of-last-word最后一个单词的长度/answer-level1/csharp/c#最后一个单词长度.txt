```
 public static int LengthOfLastWord(string s)
        {
            s = s.Trim();
            if (string.IsNullOrEmpty(s))
            {
                return 0;
            }
            if (!s.Contains(' '))
            {
                return s.Length;
            }
            return  s.Length - s.LastIndexOf(' ')-1;
            //s.Substring(s.LastIndexOf(' '),s.Length);
        }
```
