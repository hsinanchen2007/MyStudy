### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        Array.Sort(nums);
        IList<IList<int>> list= new List<IList<int>>();
        for (int k = 0; k<nums.Length - 2; ++k){
            if (nums[k]>0){
                break;
            }
            if (k>0 && nums[k]==nums[k-1]){
                continue;
            }
            for (int i = k + 1, j = nums.Length -1; i<j;){
                int tmp = nums[i]+nums[j]+nums[k];
                if (tmp == 0){
                    list.Add(new List<int>{nums[i],nums[j],nums[k]});
                    while (i<j && nums[i]==nums[++i]);
                    while (i<j && nums[j]==nums[--j]);
                }else if (tmp < 0) {
                    while (i<j && nums[i]==nums[++i]);
                }else{
                    while (i<j && nums[j]==nums[--j]);
                }
            }
        }
        return list;
    }
}
```