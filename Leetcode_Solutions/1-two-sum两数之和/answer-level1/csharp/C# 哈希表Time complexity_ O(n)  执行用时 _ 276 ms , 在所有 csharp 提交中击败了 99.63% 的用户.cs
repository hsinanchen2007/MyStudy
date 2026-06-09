```
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Hashtable map = new Hashtable();
        for (int i = 0; i < nums.Length; i++)
        {
            int complement = target - nums[i];
            if (map.ContainsKey(complement))
            {
                return new int[] { Convert.ToInt32(map[complement]), i };
            }
            if (!map.ContainsKey(nums[i]))
            {
                map.Add(nums[i], i);
            }
        }
        return null;
    }
}
```

[微软-内推]（北京上海苏州无锡）大量职位招人，长期有效 https://leetcode-cn.com/circle/article/Cj79fP/