投票法思路：众数总比非众数多 因此最终能让票数count保持大于0的数就是众数。 注意:每当count变回0时就更换候选人，继续统计后续票数。 

### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {       
       //投票法   
        int condidate = nums[0];
        int count = 1;
        for(int j = 1;j<nums.Length;j++)
        {   
            if(count == 0)
            {
                count = 1;
                condidate = nums[j];
                continue;
            }            
            if(nums[j] != condidate)
            {
                count--;
            }   
            else
            {
                count++;
            }                
        }
        return condidate;                  
    }
}
```