### 解题思路
真的不会位运算，但是这么写似乎没毛病，欢迎大神指正

### 代码

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        int result=0;
        Array.Sort(nums);
        for(int i=1;i<=nums.Length;i+=2)
        {
            if(i<nums.Length)
            {
                if(nums[i-1]!=nums[i])
                {
                    result= nums[i-1];
                    break;
                }
            }
            else
            {
                result= nums[i-1];
                break;
            }
        }
        return result;
    }
}
```