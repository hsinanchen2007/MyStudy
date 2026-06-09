```
    public string[] FindWords(string[] words)
    {
        List<string> res = new List<string>();
        var s1 = "QWERTYUIOP";
        var s2 = "ASDFGHJKL";
        var s3 = "ZXCVBNM";

        HashSet<char> GetHashSet(string s)
        {
            HashSet<char> temp = new HashSet<char>();
            for (int i = 0; i < s.Length; i++)
            {
                temp.Add(s.ElementAt(i));
            }
            return temp;
        }

        var h1 = GetHashSet(s1);
        var h2 = GetHashSet(s2);
        var h3 = GetHashSet(s3);

        for (int i = 0; i < words.Length; i++)
        {
            var str = words.ElementAt(i).ToUpper();
            HashSet<char> hw = GetHashSet(str);
            if (h1.IsSupersetOf(hw))
            {
                res.Add(words[i]);
            }else if (h2.IsSupersetOf(hw))
            {
                res.Add(words[i]);
            }else if (h3.IsSupersetOf(hw))
            {
                res.Add(words[i]);
            }
        }
        return res.ToArray();
    }
```
