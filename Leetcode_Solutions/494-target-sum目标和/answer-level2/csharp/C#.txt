方法一：数组
```csharp
public class Solution {
    public int FindTargetSumWays(int[] nums, int S)
    {
        if (nums.Length == 0 || S > 1000 || S < -1000) return 0;
        int[] arr = new int[2001];
        arr[1000 + nums[0]]++;
        arr[1000 - nums[0]]++;
        for(int i = 1; i < nums.Length; i++)
        {
            int[] temp = new int[2001];
            for(int j = 0; j < 2001; j++)
            {
                if(arr[j] > 0)
                {
                    temp[j + nums[i]] += arr[j];
                    temp[j - nums[i]] += arr[j];
                }
            }
            arr = temp;
        }
        return arr[1000 + S];
    }
}
```

方法二：递归（会超时）
```csharp
public class Solution {
    public int FindTargetSumWays(int[] nums, int S) {
        if(nums.Length == 0) return 0;
        int sum = nums.Sum();
        if(S == sum || S == sum * -1) return (int)Math.Pow(2, nums.Count(a => a == 0));
        if(S > sum || S < sum * -1) return 0;
        int p = FindTargetSumWays(nums.Skip(1).ToArray(), S - nums[0]);
        int n = FindTargetSumWays(nums.Skip(1).ToArray(), S + nums[0]);
        return p + n;
    }
}
```

方法二：优化递归（不超时但很慢）
```csharp
public class Solution {
    public int FindTargetSumWays(int[] nums, int S)
    {
        if (nums.Length == 0) return 0;
        int sum = ArraySum(nums);
        if (S == sum || S == sum * -1) return (int)Math.Pow(2, nums.Count(a => a == 0));
        if (S > sum || S < sum * -1) return 0;
        int p = FindTargetSumWays(NextArray(nums), S - nums[0]);
        int n = FindTargetSumWays(NextArray(nums), S + nums[0]);
        return p + n;
    }
    public int[][] grid = null;
    public int[] arrSum = null;
    public int[] NextArray(int[] arr)
    {
        if (grid == null)
        {
            grid = new int[arr.Length + 1][];
            arrSum = new int[arr.Length + 1];
            for (int i = 0; i < arr.Length; i++)
            {
                grid[arr.Length - i] = arr.Skip(i).ToArray();
                arrSum[arr.Length - i] = grid[arr.Length - i].Sum();
            }
            grid[0] = new int[0];
        }
        return grid[arr.Length - 1];
    }
    public int ArraySum(int[] arr)
    {
        if (arrSum == null) return arr.Sum();
        return arrSum[arr.Length];
    }
}
```