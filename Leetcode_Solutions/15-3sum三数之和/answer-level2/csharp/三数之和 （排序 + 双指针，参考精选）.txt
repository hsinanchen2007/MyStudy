### 解题思路
此处撰写解题思路

### 代码

```csharp
public class Solution {
    public IList<IList<int>> ThreeSum(int[] nums) {
        var res = new List<IList<int>>();  //注意这里 创建元素为数组的列表
                //特例 数组为null 或者 长度小于3
            if (nums.Length < 3 || nums == null)
                return res;
            else
            {
                 Array.Sort(nums); //系统自带排序 只能从小到大
                //quick_sort(nums, 0, nums.Length-1);
                for (int i = 0; i < nums.Length; i++)
                {                                  
                    if (nums[i] > 0)
                        continue;
                    if (i > 0 && nums[i] == nums[i - 1])//排除重复的i
                        continue;
                    int L = i + 1;  //一直比i大1 
                    int R = nums.Length - 1;
                    while (L < R)
                    { 
                        if (nums[i] + nums[L] + nums[R] == 0)
                        {
                            res.Add(new int[] { nums[i], nums[L], nums[R] });
                            while (L < R && nums[L] == nums[L + 1])  //排除重复的L
                                L = L + 1;
                            while (L < R && nums[R] == nums[R - 1])  //排除重复的R
                                R = R - 1;
                            if(L<R) //防止{0,0,0}这种情况使i出界
                            {
                                L = L + 1;    //最后一个重复值的下一位
                                R = R - 1;
                            }
                        }
                        if (nums[i] + nums[L] + nums[R] > 0) R--;  //总值大了右指针左移
                        if (nums[i] + nums[L] + nums[R] < 0) L++;  //总值小了左指针右移
                    }                                        
                }
               return res;
            } 
            
    }
}
```