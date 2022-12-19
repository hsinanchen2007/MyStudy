**1.动态规划问题;
2.定义一个存储答案的ans并初始化,sum为存储最大子序和的一个变量,遍历数组,sum只要大于0就一直加,如果sum小于0,将当前数字赋给sum,ans每次存储sum 和 ans的最大值即可;
3.完结。**

        public int maxSubArray(int[] nums) {
            int sum = 0;
            int ans = nums[0];
            for (int i = 0; i < nums.length; i++) {
                if (sum > 0)
                    sum += nums[i];
                else
                    sum = nums[i];
                ans = Math.max(ans, sum);
            }
            return ans;
        }