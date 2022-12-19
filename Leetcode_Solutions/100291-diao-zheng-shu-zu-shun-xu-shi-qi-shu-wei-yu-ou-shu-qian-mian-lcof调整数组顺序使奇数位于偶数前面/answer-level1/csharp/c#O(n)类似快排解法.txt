### 代码

```csharp
public class Solution {
    public int[] Exchange(int[] nums) {
        int low = 0;
        int high = nums.Length - 1;
        while(low <= high)
        {
            if(nums[low] % 2 == 0)
            {
                int t = nums[low];
                nums[low] = nums[high];
                nums[high] = t;
                high--;
            }
            else
            {
                low++;
            }
        }
        
        return nums;
    }
}
```