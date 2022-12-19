### 解题思路
使用投票法，每次假设数组中的下一个值为众数，遇到假设的众数，投票+1；遇到不是众数，投票-1；每次投票器置0时，代表众数和非众数数量抵消，剩下的一定也是众数多于非众数，再使用下一个数字作为假设众数，继续遍历，知道数据结束；

### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        var guess = nums[0];
        var count = 0;
        for (int index = 0; index < nums.Length - 1; index++)
        {
            if (nums[index] == guess)
                count++;
            else
                count--;

            if (count == 0)
            {
                guess = nums[index + 1];
            }
        }

        return guess;
    }
}
```