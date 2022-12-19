C#无论使用字典（Dictionary）还是哈希表（HashTable），都需要通过遍历所有键来选出符合的键，Java的HashTable有特定的get方法可以获取键，如果一定要用哈希表来解决的话，而你用数组的值来作为键，当数组元素重复时，是无法添加的，会报出异常

__使用字典来解决，这会超出时限__

```C# []
   public int[] TwoSum(int[] nums, int target)
    {
        int[] result = new int[2];
        Dictionary<int, int> dic = new Dictionary<int, int>();
        for (int i = 0; i < nums.Length; i++)
        {
            dic.Add(i,nums[i]);
        }

        for (int i = 0; i < nums.Length; i++)
        {
            int v = target - nums[i];
            foreach (KeyValuePair<int,int> kvp in dic)
            {
                if (dic.ContainsValue(v) &&kvp.Value.Equals(v)&&kvp.Key!=i)
                {
                    result[0] = i;
                    result[1] = kvp.Key;
                    return result;
                }
            }
        }
        return result;
        
    }
```

__不使用字典__


``` C# []
   public int[] TwoSum(int[] nums, int target)
    {
        int[] result = new int[2];
        for (int i = 0; i < nums.Length; i++)
        {            
            int int_j = target -nums[i];
            int j;
            j = Array.IndexOf(nums, int_j);
            if (j == -1) { continue; }
            if (j != i)
            {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
        return result;
    }
```
第二种方法利用了Array.IndexOf来找出符合的索引，而一旦返回-1说明数组无此元素