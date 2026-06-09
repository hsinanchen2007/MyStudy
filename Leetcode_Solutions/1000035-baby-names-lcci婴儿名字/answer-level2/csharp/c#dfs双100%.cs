### 解题思路
1.用一个二维数组保存相似关系，但这样会导致很多无用的遍历而超时，改用HashSet<int>[]保存关系就行
2.用dfs不断往下找相似的名字，并把数量累加
3.每个名字只查一次，为了避免重复查，需要用passFlags做标记来

### 代码

```csharp
public class Solution {
    public string[] TrulyMostPopular(string[] names, string[] synonyms) {
        int[] counts = new int[names.Length];
        string[] realNames = new string[names.Length];
        Dictionary<string, int> nameIndexMap = new Dictionary<string, int>();
        for(int i = 0; i < names.Length; i++)
        {
            string str = names[i];
            string[] strs = str.Split('(');
            string name = strs[0];
            string numStr = strs[1].Substring(0, strs[1].Length - 1);
            int num = int.Parse(numStr);
            counts[i] = num;
            realNames[i] = name;

            nameIndexMap.Add(name, i);
        }

        HashSet<int>[] connects = new HashSet<int>[names.Length];
        for(int i = 0; i < connects.Length; i++)
        {
            connects[i] = new HashSet<int>();
        }

        for(int i = 0; i < synonyms.Length; i++)
        {
            string syn = synonyms[i];
            syn = syn.Substring(1, syn.Length - 2);
            string[] synNames = syn.Split(',');

            int index1 = 0;
            int index2 = 0;
            if(nameIndexMap.TryGetValue(synNames[0], out index1) && nameIndexMap.TryGetValue(synNames[1], out index2))
            {
                connects[index1].Add(index2);
                connects[index2].Add(index1);
            }
        }

        List<string> totalCountList = new List<string>();
        bool[] passFlags = new bool[names.Length];
        for(int i = 0; i < names.Length; i++)
        {
            if(!passFlags[i])
            {
                int minNameIndex = -1;
                int c = Search(connects, counts, i, passFlags, realNames, ref minNameIndex);
                totalCountList.Add(realNames[minNameIndex] + "(" + c + ")");
            }
        }

        return totalCountList.ToArray();
    }

    int Search(HashSet<int>[] connects, int[] counts, int index, bool[] passFlags, string[] realNames, ref int minNameIndex)
    {
        int c = counts[index];
        passFlags[index] = true;

        if(minNameIndex < 0)
        {
            minNameIndex = index;
        }
        else
        {
            if(string.Compare(realNames[index], realNames[minNameIndex]) < 0)
            {
                minNameIndex = index;
            }
        }

        HashSet<int> connectSet = connects[index];
        foreach(int nextIndex in connectSet)
        {
            if(!passFlags[nextIndex])
            {
                c += Search(connects, counts, nextIndex, passFlags, realNames, ref minNameIndex);
            }
        }

        return c;
    }
}
```