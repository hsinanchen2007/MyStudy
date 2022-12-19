一边遍历一边移动，记录下0的个数为zeroCount，最后把数组后zeroCount个元素置为0。
```
public class Solution {
    public void MoveZeroes(int[] nums) {
        int zeroCount = 0;
        
        for(int i = 0; i < nums.Length; i++)
        {
            if(nums[i] != 0)
                nums[i - zeroCount] = nums[i];    // 向前移动
            else
                zeroCount++;  // 记录0的个数
        }
        for(int i = nums.Length - zeroCount; i < nums.Length; i++)
        {
            nums[i] = 0;
        }
    }
}
```
