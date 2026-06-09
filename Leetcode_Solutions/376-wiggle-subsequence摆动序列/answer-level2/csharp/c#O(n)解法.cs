### 解题思路
首先要找到第一个不相等的两个数
假如升序连续有多个数，把头尾保留，中间的删掉
连续降序的同上一样处理
注意相等的数

### 代码

```csharp
public class Solution {
    public int WiggleMaxLength(int[] nums) {
        if(nums.Length <= 1)
        {
            return nums.Length;
        }

        if(nums.Length <= 2)
        {
            if(nums[0] != nums[1])
            {
                return 2;
            }
            
            return 1;
        }
        


        int startIndex = 0;
        int preNum = nums[0];
        for(int i = 1; i < nums.Length; i++)
        {
            if(nums[i] != preNum)
            {
                break;
            }

            startIndex++;
        }

        if(startIndex >= nums.Length - 1)
        {
            return 1;
        }

        bool up = nums[startIndex] > nums[startIndex + 1];

        int deleteCount = 0;
        for(int i = startIndex + 2; i < nums.Length; i++)
        {
            if(up)
            {
                if(nums[i] <= nums[i - 1])
                {
                    deleteCount++;
                }
                else
                {
                    up = false;
                }
            }
            else
            {
                if(nums[i] >= nums[i - 1])
                {
                    deleteCount++;
                }
                else
                {
                    up = true;
                }
            }
        }

        return nums.Length - startIndex - deleteCount;
    }
}
```