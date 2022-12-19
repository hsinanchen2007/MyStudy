### 解题思路
1刷：
    先排序，再比较相邻两个数是否相等

### 代码

```csharp
public class Solution {
    public int FindRepeatNumber(int[] nums) {
        Array.Sort(nums);       
        for(int i=0;i<nums.Length;i++){
            if(nums[i]==nums[i+1])
                return nums[i];            
        }
        return 0;
    }
}
```