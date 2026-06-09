
### 代码

```csharp
public class Solution {
    public int[] SearchRange(int[] nums, int target)
        {
            int left = 0;
            int right = nums.Length - 1;
            int index = -1;

            while (left <= right)
            {
                int mid = left + (right - left) / 2;
                if (nums[mid] == target)
                {
                    index = mid;
                    break;
                }
                else if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else
                {
                    left = mid + 1;
                }
            }

            if (index == -1)
            {
                return new int[] { -1, -1 };
            }
            else
            {
                int leftIndex = index;
                int rightIndex = index;

                for (int i = leftIndex; i >= 0 && nums[i] == target; i--)
                {
                        leftIndex = i;
                }

                for (int i = rightIndex; i < nums.Length && nums[i] == target; i++)
                {
                        rightIndex = i;
                }

                return new int[] { leftIndex, rightIndex };
            }
        }
}
```