```
public class Solution {
    public IList<string> CommonChars(string[] A) {
        List<Dictionary<char, int>> list = new List<Dictionary<char, int>>();
        foreach (var str in A)
        {
            Dictionary<char, int> dic = new Dictionary<char, int>();
            foreach (var cha in str)
            {
                if (!dic.ContainsKey(cha))
                {
                    dic.Add(cha, 1);
                }
                else
                {
                    dic[cha] += 1;
                }
            }
            list.Add(dic);
        }
        list.Sort((x, y) => x.Count.CompareTo(y.Count));
        var minListItem = list[0];
        List<string> res = new List<string>();
        foreach (var c in minListItem.Keys)
        {
            int flag = 0;
            int minNum = minListItem[c];
            for (int i = 1; i < list.Count; i++)
            {
                if (list[i].ContainsKey(c))
                {
                    flag++;
                    minNum = Math.Min(minNum, list[i][c]);
                }
            }
            if (flag == list.Count - 1)
            {
                for (int i = 0; i < minNum; i++)
                {
                    res.Add(c.ToString());
                }
            }
        }
        return res;
    }
}
```
