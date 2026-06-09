```
public class Solution {
    public IList<string> SubdomainVisits(string[] cpdomains) {
        List<string> res = new List<string>();
        Dictionary<string, int> dic = new Dictionary<string, int>();
        for (int i = 0; i < cpdomains.Length; i++)
        {
            string c = cpdomains[i];

            var c2 = c.Split(' ');
            int c3 = int.Parse(c2[0]);
            var c4 = c2[1];

            var c5 = c4.Split('.');

            string c6 = string.Empty;
            for (int j = 0; j < c5.Length; j++)
            {
                c6 = c5[j];
                for (int k = j+1; k < c5.Length; k++)
                {
                    c6 += "." + c5[k];
                }
                if (!dic.ContainsKey(c6))
                {
                    dic.Add(c6, c3);
                }
                else
                {
                    dic[c6] += c3;
                }
            }
        }

        foreach (var kv in dic)
        {
            string c7 = string.Empty;
            c7 += kv.Value + " " + kv.Key;
            res.Add(c7);
        }
        return res;
    }
}
```
