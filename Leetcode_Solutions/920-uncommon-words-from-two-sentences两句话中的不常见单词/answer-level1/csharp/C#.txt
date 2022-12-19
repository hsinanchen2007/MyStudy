```
public class Solution {
     public string[] UncommonFromSentences(string A, string B)
    {
        List<string> res = new List<string>();
        var a1 = A.Split(' ');
        var a2 = B.Split(' ');

        Dictionary<string, int> dicA = new Dictionary<string, int>()
            ;
        Dictionary<string, int> dicB = new Dictionary<string, int>()
            ;
        dicA = GetDic(a1, dicA);
        dicB = GetDic(a2, dicB);

        foreach (var kv in dicA)
        {
            if (!dicB.ContainsKey(kv.Key) && kv.Value == 1)
            {
                res.Add(kv.Key);
            }
        }


        foreach (var kv in dicB)
        {
            if (!dicA.ContainsKey(kv.Key) && kv.Value == 1)
            {
                res.Add(kv.Key);
            }
        }

        return res.ToArray();
    }

    private Dictionary<string, int> GetDic(string[] a1, Dictionary<string, int> dicA)
    {
        foreach (var str in a1)
        {
            if (!dicA.ContainsKey(str))
            {
                dicA.Add(str, 1);
            }
            else
            {
                dicA[str] += 1;
            }
        }

        return dicA;
    }
}
```
