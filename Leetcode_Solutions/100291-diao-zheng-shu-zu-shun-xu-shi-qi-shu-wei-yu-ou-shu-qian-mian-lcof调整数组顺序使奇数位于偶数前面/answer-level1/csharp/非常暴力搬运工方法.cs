### 解题思路
先遍历数组的每个元素，找出奇数元素并提取出值，以免被覆盖
再对此元素之前的所有元素往后移一位，（有些暴力但我想不出别的了）
把奇数插入到前半部分的奇数串的末尾（用ins变量记录奇数串的长度）
最后输出
### 代码

```csharp
public class Solution {
    public int[] Exchange(int[] nums) {
        int ins = 0;
        for(int i = 0; i< nums.Length;i++)
        {
            if(nums[i] %2 == 1)
            {   
                int aim =  nums[i];
                for(int j = i; j > ins; j--)
                {
                    nums[j] = nums[j-1];
                }
                nums[ins] = aim;
                ins++;
            }
        }
        return nums;
    }
}
```