个人解法
遍历
时间复杂度O(n^2)，空间复杂度O(1)
```
public class Solution {
    public int[] TwoSum(int[] nums, int target)
    {
        int[] n = new int[2];
        int i = 0, j = 0;
        for (i = 0; i < nums.Length; i++)
        {
            for (j = i + 1; j < nums.Length; j++)
            {
                if (nums[i] + nums[j] == target)
                {
                    n[0] = i;
                    n[1] = j;
                    return n;
                }
            }
        }

        n[0] = i;
        n[1] = j;
        return n;
    }
}
```

学习解法
Hash表
时间复杂度O(n)，空间复杂度O(nn)
```
public class Solution {
    public int[] TwoSum(int[] nums, int target)
    {
        //一次遍历，用hashmap检索当前值需要的目标值
        Hashtable map = new Hashtable();
        for(int i = 0; i < nums.Length; i++)
        {
            int j = target - nums[i];//计算目标值
            if(map.ContainsKey(j))
            {
                //找到目标值后返回两个下标
                return new int[] {Convert.ToInt32(map[j]),i};
            }
            if(!map.ContainsKey(nums[i]))
            {
                //将当前值和数组下标存入hashmap
                map.Add(nums[i],i);
            }
        }
        return null;
    }
}
```
