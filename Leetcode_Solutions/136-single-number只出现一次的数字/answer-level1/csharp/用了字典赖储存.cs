### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public int SingleNumber(int[] nums) {
        Dictionary<int,int> dic = new Dictionary<int, int>(nums.Length);
        for (int i = 0; i < nums.Length; i++)
        {
            if (dic.ContainsKey(nums[i]))
            {
                dic.Remove(nums[i]);
                continue;
            }
            else
            {
                dic.Add(nums[i], i);
            }
        }
        return dic.First().Key;
    }
}
```