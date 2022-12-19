```
    public int UniqueMorseRepresentations(string[] words) {
        int result = 0;
        Dictionary<char, string> dic = new Dictionary<char, string>();
        dic.Add('a', ".-");
        dic.Add('b', "-...");
        dic.Add('c', "-.-.");
        dic.Add('d', "-..");
        dic.Add('e', ".");
        dic.Add('f', "..-.");
        dic.Add('g', "--.");
        dic.Add('h', "....");
        dic.Add('i', "..");
        dic.Add('j', ".---");
        dic.Add('k', "-.-");
        dic.Add('l', ".-..");
        dic.Add('m', "--");
        dic.Add('n', "-.");
        dic.Add('o', "---");
        dic.Add('p', ".--.");
        dic.Add('q', "--.-");
        dic.Add('r', ".-.");
        dic.Add('s', "...");
        dic.Add('t', "-");
        dic.Add('u', "..-");
        dic.Add('v', "...-");
        dic.Add('w', ".--");
        dic.Add('x', "-..-");
        dic.Add('y', "-.--");
        dic.Add('z', "--..");

        Dictionary<string, int> d = new Dictionary<string, int>(); 
        for (int i = 0; i < words.Count(); i++)
        {
            char[] c = words[i].ToCharArray();
            string s = "";
            string str = "";
            for (int j = 0; j < c.Count(); j++)
            {
                if(dic.TryGetValue(c[j], out s))
                {
                    str += s;
                }
            }
            if (!d.ContainsKey(str))
            {
                d.Add(str, i);
            }
        }

        return d.Count();
    }
```
