class Solution {

    //贪心+二分查找
    //从头遍历一次，维护一个数组，保存当前遍历位置的最长上升子序列
    //而且保证每个长度的上升子序列都是最优的，即尾端数字最小
    //怎么更新？
    //遍历到一个新的数字A，那这个数字和现有最长上升子序列进行比较，找到这个数字A的应该插入的位子
    //这个位子应该是，前一个数比A小，这个位子上的数比A大，就可以用A去替换这位子上的数字，如果A
    //比现有最长上升子序列的所有数都大，那么A就插入到最后的位置，最长上升子序列的长度就增加了
    //现有最长上升子序列是递增有序的，所以可以用二分查找去找到A的位置
    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        int dp[] = new int[n];
        int max_length = 0;
        for(int item: nums) {
            int left = 0, right = max_length;
            while(left < right) {
                int pivot = (left + right) / 2;
                if(dp[pivot] < item) left = pivot+1;
                else right = pivot;
            }
            dp[left] = item;
            if(left == max_length) max_length++;
        }
        return max_length;
    }
    /*
    //动态规划
    //dp数组地设计，dp[i]表示前i个数最长上升子序列长度，dp[i] 和dp[i+1]没有任何关系
    //dp[i] 应该表示以nums[i]结尾地最长上升子序列 dp[i] = max(dp[0], dp[i] ... dp[i-1]) == dp[k] && dp[i] > dp[k]

    public int lengthOfLIS(int[] nums) {
        int n = nums.length;
        if(n == 0) return 0;
        int[] dp = new int[n];
        int max = 1;
        dp[0] = 1;
        for(int i = 1; i < n; i++) {
            int k = i-1;
            int temp = 0;
            while(k >= 0) {
                if(nums[i] > nums[k] && dp[k] > temp) {
                    temp = dp[k];
                }
                k--;
            }
            dp[i] = temp + 1;
            max = Math.max(max, dp[i]);
        }
        return max;
    }*/
}