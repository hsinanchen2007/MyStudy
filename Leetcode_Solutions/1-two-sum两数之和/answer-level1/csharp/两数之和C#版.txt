### 解题思路
两数之和，所给数组中，两层循环方式，暴力破解

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for(int i=0;i<nums.Length;i++){
            for(int j=i+1;j<nums.Length;j++){
                if(nums[i]+nums[j]==target){
                    return new int[]{i,j};                
                }
            }
        } 
        throw new InvalidCastException("No two sum solution");
    }
}
```