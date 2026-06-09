先排序，利用排序后数组的有序性，当三数之和大于目标值时让右指针左移，当三数之和小于目标值时让左指针右移

### 代码

```csharp
public class Solution 
{
    public int ThreeSumClosest(int[] nums, int target) 
    {
        Array.Sort(nums); //先对数组排序 方便后面寻找
            int sum = 0;     
            int x = Int32.MaxValue;
            for (int i = 0; i < nums.Length; i++)
            {   
                int L = i + 1;
                int R = nums.Length - 1;                    
                while (L < R)
                {
                    if (Math.Abs(nums[i] + nums[L] + nums[R] - target) < x)
                        sum = nums[i] + nums[L] + nums[R];
                    x = Math.Min(Math.Abs(nums[i] + nums[L] + nums[R] - target), x);
                    //若等于目标值 则就是最接近的情况
                    if (nums[i] + nums[L] + nums[R] == target)
                        return nums[i] + nums[L] + nums[R];                       
                    if(nums[i] + nums[L] + nums[R]>target)
                        R-=1;
                    else if(nums[i] + nums[L] + nums[R]<= target)
                    {
                        L +=1;
                    }
                }
            }
            return sum;
        //}
    }
}
```