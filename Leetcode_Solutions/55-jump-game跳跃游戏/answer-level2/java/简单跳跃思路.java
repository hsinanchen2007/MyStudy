因为要跳到最后一个位置，那么我们就从最后一个位置来，一定是能到的结果。
1. 用`last`来记录最近的，能跳到的位置。
2. 假设当前为`i`，如果`nums[i] >= (last - i)`，说明了我在当前位置`i`肯定能跳到`last`的位置，那肯定能跳到最后一个位置。
3. 这时候更新`last=i`，继续遍历上一步。
```
public class test3
{
    public boolean canJump(int[] nums)
    {
        if(nums == null || nums.length == 0) return true;

        int last = nums.length - 1; // 最近的可以跳到的位置

        for(int i = nums.length - 2;i >= 0;i--)
        {
            if(nums[i] >= (last - i))
            {
                last = i;
            }
        }
        if(last == 0) return true;
        return false;
    }

    public static void main(String[] args)
    {
        test3 of = new test3();
        int[] nums = {2,3,1,1,4};
        System.out.println(of.canJump(nums));
    }
}
```