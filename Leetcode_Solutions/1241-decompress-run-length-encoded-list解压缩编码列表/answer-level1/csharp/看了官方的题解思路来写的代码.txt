### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] DecompressRLElist(int[] nums) {
        List<int> deint=new List<int>();
        for(int i=0;i<nums.Length;i+=2)
        {
            for(int j=0;j<nums[i];j++)
            {
                deint.Add(nums[i+1]);
            }
        }
        return deint.ToArray();
    }
}
```