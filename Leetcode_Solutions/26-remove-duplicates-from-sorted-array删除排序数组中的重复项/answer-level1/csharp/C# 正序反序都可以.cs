### 解题思路
就是定义一个变量来当做下标，修改nums的值即可，最后返回下标加一
### 代码

```csharp
public class Solution {
    public int RemoveDuplicates(int[] nums) {
         if (nums.Length == 0) return 0;
            int index = 0;
            int firstVal = nums.FirstOrDefault();
            for (int i = 1; i < nums.Length; i++)
            {
                //相同
                if (nums[i] == firstVal)
                {
                    nums[index] = firstVal;
                }
                else
                {
                    index++;
                    firstVal = nums[i];
                    nums[index] = firstVal;
                }
            }
         
            return index + 1;
    }
}
```