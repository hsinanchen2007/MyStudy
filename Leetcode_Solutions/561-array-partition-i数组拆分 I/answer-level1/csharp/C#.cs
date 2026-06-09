### 解题思路
排序后偶数序号求和
### 代码

```csharp
public class Solution {
    public int ArrayPairSum(int[] nums) {
        Array.Sort(nums);
        int res = 0;
        for(int i = 0;i<nums.Length;i+=2){
            res+=nums[i];
        }
        return res;
    }
}
```