public class Solution
{

    public static void main(String args[])
    {
        Solution solution = new Solution();
        int[] ar =
        { -2, 1, -3, 4, -1, 2, 1, -5, 4 };
        System.out.println(solution.maxSubArray(ar));
        // System.out.println(solution.maxSubArrayExhaustive(ar));
        // System.out.println(solution.maxSubArrayDivid(ar));

    }

    // 动态规划
    public int maxSubArray(int[] nums)
    {

        // 初始化开始数据
        int max = nums[0];

        // 初始化开始数据
        int dp = nums[0];

        for (int i = 1; i < nums.length; i++)
        {
            // dp
            dp = Math.max(dp + nums[i], nums[i]);
            max = Math.max(max, dp);
        }
        return max;

    }

    // 暴力解法
    public int maxSubArrayExhaustive(int[] nums)
    {
        int result = Integer.MIN_VALUE;
        for (int i = 0; i < nums.length; i++)
        {
            int sum = 0;
            for (int j = i; j < nums.length; j++)
            {
                sum = sum + nums[j];
                result = Math.max(result, sum);
            }
        }
        return result;
    }

    // 包含mid 查找最大连续和
    public int maxCorssMidSum(int[] nums, int left, int right, int mid)
    {
        int leftMax = Integer.MIN_VALUE;
        int sum = 0;
        for (int i = mid; i >= left; i--)
        {
            sum += nums[i];
            if (sum > leftMax)
            {
                leftMax = sum;
            }
        }

        int rightMax = Integer.MIN_VALUE;

        sum = 0;
        for (int i = mid + 1; i <= right; i++)
        {
            sum += nums[i];
            if (sum > rightMax)
            {
                rightMax = sum;
            }
        }
        System.out.println("leftMax:" + leftMax + " rightMax:" + rightMax);

        return leftMax + rightMax;

    }

    // 左右查找
    public int maxSubArraySum(int[] nums, int left, int right)
    {
        if (left == right)
        {
            return nums[left];
        }

        int mid = (left + right) / 2;
        System.out.println("begin to left.." + "[" + left + " " + mid + " "
                + right + "]");
        int leftMax = maxSubArraySum(nums, left, mid);

        System.out.println("begin to right.." + "[" + left + " " + mid + " "
                + right + "]");
        int rightMax = maxSubArraySum(nums, mid + 1, right);

        System.out.println("begin to merge.." + "[" + left + " " + mid + " "
                + right + "]");
        int crossMax = maxCorssMidSum(nums, left, right, mid);

        int value = Math.max(crossMax, Math.max(leftMax, rightMax));

        System.out.println("[" + left + " " + mid + " " + right + "]"
                + " leftMax:" + leftMax + " crossMax:" + crossMax
                + " rightMax:" + rightMax + " value:" + value);
        return value;
    }

    // 分治算法
    public int maxSubArrayDivid(int[] nums)
    {

        int length = nums.length;
        return maxSubArraySum(nums, 0, length - 1);

    }

}