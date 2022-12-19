```csharp
public IList<IList<int>> Permute(int[] nums) {
    IList<IList<int>> ans = new List<IList<int>>();
    if(nums.Length == 0) return ans;
    if(nums.Length == 1)
    {
        ans.Add(new List<int>(){nums[0]});
    }
    else if(nums.Length == 2)
    {
        ans.Add(new List<int>(){nums[0], nums[1]});
        ans.Add(new List<int>(){nums[1], nums[0]});
    }
    else
    {
        foreach(int i in nums)
        {
            IList<IList<int>> temp = Permute(nums.Except(new int[]{ i }).ToArray());
            foreach(var list in temp)
            {
                list.Insert(0, i);
                ans.Add(list);
            }
        }
    }
    return ans;
}
```
但是比较慢，因为递归过程中存在重复的操作，稍微优化一下将每次递归的结果存起来，再次遇到可以直接调用
```csharp
public Dictionary<string, int[][]> dic =
            new Dictionary<string, int[][]>();

public IList<IList<int>> Permute(int[] nums)
{
    IList<IList<int>> ans = new List<IList<int>>();
    string key = string.Join(",", nums.Select(a => a.ToString()).ToArray());
    if (dic.ContainsKey(key))
    {
        foreach (int[] arr in dic[key])
        {
            ans.Add(arr.ToList());
        }
        return ans;
    }
    if (nums.Length == 0) return ans;
    if (nums.Length == 1)
    {
        ans.Add(new List<int>() { nums[0] });
    }
    else if (nums.Length == 2)
    {
        ans.Add(new List<int>() { nums[0], nums[1] });
        ans.Add(new List<int>() { nums[1], nums[0] });
    }
    else
    {
        foreach (int i in nums)
        {
            IList<IList<int>> temp = Permute(nums.Except(new int[] { i }).ToArray());
            foreach (var list in temp)
            {
                list.Insert(0, i);
                ans.Add(list);
            }
        }
    }
    int[][] dicValue = new int[ans.Count][];
    for (int i = 0; i < ans.Count; i++)
    {
        dicValue[i] = ans[i].ToArray();
    }
    dic.Add(key, dicValue);
    return ans;
}
```