### 解题思路
双指针

### 代码

```csharp
public class Solution {
    public int[] Exchange(int[] nums) {
        if(nums == null || nums.Length == 0 || nums.Length == 1)
        {
            return nums;
        }

        int i = 0;
        int j = 0;
        while(j < nums.Length)
        {
            if(nums[j] % 2 != 0)
            {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
            j++;
        }

        return nums;
    }
}
```