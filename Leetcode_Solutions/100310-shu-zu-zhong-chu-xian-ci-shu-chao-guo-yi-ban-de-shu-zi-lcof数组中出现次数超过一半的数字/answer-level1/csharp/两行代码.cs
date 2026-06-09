### 解题思路
先排序，由于众数的数量在一半以上，故中间位置的必为所求

### 代码

```csharp
public class Solution {
    public int MajorityElement(int[] nums) {
        Array.Sort(nums);
        return nums[nums.Length/2];
    }
}
```