```csharp
public class Solution {
    public void NextPermutation(int[] nums) {
        for(int i = nums.Length - 1; i > 0; i--)
        {
            if(nums[i] > nums[i - 1])
            {
                int left = nums.Length - 1;
                for(int j = i; j < nums.Length - 1; j++)
                {
                    if(left < j)
                    {
                        break;
                    }
                    int temp1 = nums[j];
                    nums[j] = nums[left];
                    nums[left] = temp1;
                    left--;
                }
                int k = i;
                while(nums[i - 1] >= nums[k])
                {
                    k++;
                }
                int temp2 = nums[k];
                nums[k] = nums[i - 1];
                nums[i - 1] = temp2;
                return;
            }
        }
        Array.Sort(nums);
    }
}
```