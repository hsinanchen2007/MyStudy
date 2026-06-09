import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class Solution {
    public List<Integer> largestDivisibleSubset(int[] nums) {
        /**   nums=[1,2,4,8] 先升序排序
         *   dp[i]=[1,1,1,1] 表示 num[i]可以整除的元素个数
         * last[i]=[0,0,0,0] 表示可以被num[i]整除的最大元素的下标，此数组的作用可以跟踪除数与被除数间的关系
         */
        if(null==nums||nums.length<1){
            return new ArrayList();
        }
        int N = nums.length;
        int[] dp = new int[N];
        int[] last = new int[N];
        Arrays.fill(dp, 1);
        Arrays.sort(nums);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] % nums[j] != 0) continue;
                if (dp[i] > dp[j]) continue;
                dp[i] = dp[j] + 1;
                last[i] = j;
            }
        }
        //找出整除元素的总个数   最大的一个  的下标
        int idx = 0;
        for (int i = 1; i < N; i++) {
            if (dp[i] > dp[idx]) idx = i;
        }
        List<Integer> ans = new ArrayList<>();
        while (idx != 0) {
            ans.add(0, nums[idx]);
            idx = last[idx];

        }
        if (ans.size() < 1) {
            ans.add(nums[0]);
        } else if (ans.get(0) % nums[idx] == 0) {
            ans.add(0,nums[idx]);
        }
        return ans;
    }

    public static void main(String[] args) {
        int[] A =new int[]{1};
        Solution solution= new Solution();
        solution.largestDivisibleSubset(A);
    }
}