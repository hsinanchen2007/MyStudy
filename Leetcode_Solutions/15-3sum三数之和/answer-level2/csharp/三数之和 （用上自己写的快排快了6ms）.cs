### 解题思路

### 代码

```csharp
public class Solution {
     public void quick_sort(int[] arr, int start, int end)
        {
            int i = start;
            int j = end;
            int dir = -1;
            if (end <= start)
                return;
            int temp = arr[start];
            while (i < j)
            {
                if (dir == -1)
                {
                    if (arr[j] > temp && i < j) j--;
                    else 
                    { 
                        arr[i] = arr[j]; i++; dir = 1;
                    }
                }
                if (dir == 1)
                {
                    if (arr[i] < temp && i<j) i++;
                    else
                    {
                        arr[j] = arr[i]; j--; dir = -1;
                    }
                }
            }
                arr[i] = temp;                                     
                quick_sort(arr, start, i - 1);                
                quick_sort(arr, i + 1, end);                       
        }
    public IList<IList<int>> ThreeSum(int[] nums) {
        var res = new List<IList<int>>();
                //特例 数组为null 或者 长度小于3
            if (nums.Length < 3 || nums == null)
                return res;
            else
            {
                 //Array.Sort(nums); //系统自带排序 只能从小到大
                quick_sort(nums, 0, nums.Length-1);
                for (int i = 0; i < nums.Length; i++)
                {                                  
                    if (nums[i] > 0)
                        continue;
                    if (i > 0 && nums[i] == nums[i - 1])
                        continue;
                    int L = i + 1;
                    int R = nums.Length - 1;
                    while (L < R)
                    { 
                        if (nums[i] + nums[L] + nums[R] == 0)
                        {
                            res.Add(new int[] { nums[i], nums[L], nums[R] });
                            while (L < R && nums[L] == nums[L + 1])
                                L = L + 1;
                            while (L < R && nums[R] == nums[R - 1])
                                R = R - 1;
                            if(L<R)
                            {
                                L = L + 1;
                                R = R - 1;
                            }
                        }
                        if (nums[i] + nums[L] + nums[R] > 0) R--;
                        if (nums[i] + nums[L] + nums[R] < 0) L++;
                    }                                        
                }
               return res;
            } 
            
    }
}
```