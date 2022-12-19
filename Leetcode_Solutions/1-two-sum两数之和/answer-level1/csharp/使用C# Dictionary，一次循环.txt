```
public static int[] GetSum(int[] nums, int target )
{
    var result = new int[2];
    var dic = new Dictionary<int, int>();
    for (var i = 0; i < nums.Length; i++)
    {
        if (dic.ContainsKey(nums[i]))
        {
            result[0] = dic.GetValueOrDefault(nums[i]);
            result[1] = i;
            return result;
        }

        if (dic.ContainsKey(target - nums[i]))
        {
            dic[target - nums[i]] = i;
        }
        else
        {
            dic.Add(target - nums[i], i);
        }
    }
    return null;
}
```
target-nums[1]作为key，索引作为value存入dic