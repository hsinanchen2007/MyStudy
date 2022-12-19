**方法一：动态规划**
```
class Solution {
    /**
    * 思路：
    * 由题一个元素长度为1，如果后面元素比它大则长度+1，如果比它小则不加。
    * (1) 创建一个数组用来存储原数组从头开始到每个位置包含当前元素的最长上升子序列长度；
    * (2) 外层循环遍历以哪个元素结尾，1个元素长度为1，从第二个元素开始遍历，
    *       内层循环从前往后遍历和结尾元素比较并记录结尾元素的最长上升子序列长度；
    * (3) 外层循环每遍历一次，记录当前最长上升子序列长度；
    */
    public int lengthOfLIS(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        int[] dp = new int[nums.length];
        dp[0] = 1;
        int ans = 1;
        for (int i = 1; i < dp.length; i++) {
            int len = 1;
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    len = Math.max(len, dp[j] + 1);
                }
            }
            dp[i] = len;
            ans = Math.max(ans, dp[i]);
        }
        return ans;
    }
}
```


**方法二：动态规划 + 二分法**
```
class Solution {
    /**
    * 思路：
    * 同方法一，在记录数组中按二分法查找位置减少时间。
    * (1) 创建一个数组，记录最长上升子序列；
    * (2) 外层循环依次从原数组中取出元素，从第一个元素开始存入记录数组，
    *     内层循环遍历记录数组，将当前取出的元素存入记录数组中合适位置，
    *     保证当前遍历到的元素存储在能达到的最长上升子序列位置。
    * (3) 外层遍历每遍历一次，记录当前元素应该在的位置和能达到的最长上升子序列长度。
    */
    public int lengthOfLIS(int[] nums) {
        int[] lens = new int[nums.length];
        int ans = 0;
        for(int num : nums) {
            int i = 0, j = ans;
            while(i < j) {
                int m = (i + j) / 2;
                if(lens[m] < num){
                    i = m + 1;
                }else {
                    j = m;
                }
            }
            lens[i] = num;
            // 如果ans == j，代表记录数组中的所有元素都比当前元素小
            if(ans == j){
                ans++;
            }
        }
        return ans;
    }
}
```
