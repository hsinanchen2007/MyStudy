方法一 dictionary
`public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int, int> dic = new Dictionary<int, int>();
            for (int i = 0; i < nums.Length; i++)
            {
                if (dic.ContainsKey(target-nums[i])&&dic[target - nums[i]]!= i)
                {
                    
                    return new int[] { dic[target - nums[i]] ,i};
                }
                if (!dic.ContainsKey(nums[i]))
                {
                    dic.Add(nums[i], i);
                }
            }
            return new int[] { 0, 0 };
    }
}`
方法二 双层for
`public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        for (int i = 0; i < nums.Length; i++)
            {
                for (int j = i + 1; j < nums.Length; j++)
                {
                    if (nums[i] + nums[j] == target)
                    {
                        return new int[] { i, j };
                    }
                }
            }
            return new int[] { 0, 0 };
    }
}`

对比效果在网站上 双层for内存占用和dictionary相差不多，但速度很慢
在我自己手写的数组中，100000000个有序数中，双层for速度远远高于dictionary，原理不明，希望有大佬解答