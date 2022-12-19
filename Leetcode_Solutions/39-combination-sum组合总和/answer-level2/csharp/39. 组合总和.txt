```
public IList<IList<int>> CombinationSum(int[] candidates, int target)
{
    Array.Sort(candidates);
    var current = new List<int>();
    var result = new List<IList<int>>();
    Backtrack(candidates, 0, target, current, result);
    return result;
}

public void Backtrack(int[] candidates, int start, int target, List<int> current, List<IList<int>> result)
{
    int currentSum = current.Sum();
    if (currentSum == target)
    {
        result.Add(new List<int>(current));
    }
    else if (currentSum > target)
    {
        return;
    }

    for (int index = start; index < candidates.Length; index++)
    {
        current.Add(candidates[index]);
        // 这里index不用+1，因为当前数字可以重复出现
        Backtrack(candidates, index, target, current, result);
        current.RemoveAt(current.Count - 1);
    }
}
```