### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int FindKthLargest(int[] nums, int k) {
        if(k < nums.Length / 2)   
            return nums.OrderByDescending(i => i).Skip(k - 1).First();
        else
            return nums.OrderBy(i => i).Skip(nums.Length - k).First();
    }
}
```