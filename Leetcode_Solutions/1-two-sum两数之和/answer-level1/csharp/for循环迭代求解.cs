### 解题思路
用两次for循环，遍历数组找出符合条件的两个数，取出这两个数的下标放进新定义的数组中

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int []targets = new int[2];
        for(int i=0;i<nums.Length;i++)
        {
            for(int j=i+1;j<nums.Length;j++)
            {
                if(nums[i]+nums[j]==target) 
                {
                    targets[0]=i;
                    targets[1]=j;
                    break;                    
                }

            }
        }
        return targets;
    }
}
```