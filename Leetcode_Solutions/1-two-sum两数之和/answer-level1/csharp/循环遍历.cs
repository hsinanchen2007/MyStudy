### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        int[] a=new int[2];
for(int i=0;i<nums.Length;i++)
{
    for(int j=i+1;j<nums.Length;j++)
    {
if(nums[i] + nums[j]==target)
{
    a[0]=i;
    a[1]=j;
    return a;
}
    }
}
return a;
    }
}
```