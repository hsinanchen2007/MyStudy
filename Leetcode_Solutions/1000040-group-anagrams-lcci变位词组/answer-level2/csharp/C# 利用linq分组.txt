利用linq的group进行分组


 public static IList<IList<string>> GroupAnagrams(string[] strs)
        {
            return strs.GroupBy(i =>new string(i.OrderBy(j => j).ToArray())).Select(i=>i.ToArray()).ToArray();
        }