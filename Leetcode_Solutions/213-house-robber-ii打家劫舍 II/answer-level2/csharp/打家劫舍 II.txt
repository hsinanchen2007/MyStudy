### 解题思路
结合简单的打家劫舍，这次的只需要两次调用上一次的方法即可（去头数组，去尾数组谁的结果更大）

### 代码

```csharp
public class Solution {
 public int Rob(int[] nums)
        {
            if (nums.Length == 1)
            {
                return nums[0];
            }
            var array1 = nums.Skip(1).Take(nums.Length-1).ToArray();
            var array2 = nums.Skip(0).Take(nums.Length-1).ToArray();
            return Math.Max(Rob1(array1), Rob1(array2));
        }

        public int Rob1(int[] nums)
        {
            int preMax = 0;
            int currentMax = 0;
            foreach (var item in nums)
            {
                int temp = currentMax;
                currentMax = Math.Max(preMax + item, currentMax);
                preMax = temp;
            }

            return currentMax;
        }
}
```