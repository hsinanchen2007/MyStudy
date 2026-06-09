### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public IList<IList<int>> FourSum(int[] nums, int target) {
            var res = new List<IList<int>>();
            //特例 1.长度小于4
            if (nums.Length < 4)
                return res;            
            else
            {
                Array.Sort(nums);              
                for (int i = 0; i < nums.Length-3; i++)
                {
                    if (i > 0 && nums[i] == nums[i - 1])
                        continue;
                    for (int j = i + 1; j < nums.Length-2; j++)
                    {
                        if (j > i+1 && nums[j] == nums[j - 1])
                             continue;
                        int L = j + 1;
                        int R = nums.Length - 1;
                        while (L < R)
                        {
                            if (nums[i] + nums[j] + nums[L] + nums[R] == target)
                            {   
                                res.Add(new int[]{ nums[i],nums[j],nums[L],nums[R]});
                                while (L < R && nums[L] == nums[L + 1])
                                 L++;
                                while (L < R && nums[R] == nums[R - 1])
                                 R--;  
                                  if (L < R) //防止{0,0,0}这种情况使i出界
                                {
                                    L++;    //最后一个重复值的下一位
                                    R--;
                                }                         
                            }
                            if (nums[i] + nums[j] + nums[L] + nums[R] > target)
                                R--;
                            if (nums[i] + nums[j] + nums[L] + nums[R] < target)
                                L++;
                        }
                    }
                }
             return res;
            }        

    }
}
```