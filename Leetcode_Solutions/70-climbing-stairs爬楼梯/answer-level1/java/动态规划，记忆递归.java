class Solution {
    public int climbStairs(int n) {

        int[] memo = new int[n + 1];
        return climbStairs(n,memo);
    }

    public int climbStairs(int n, int[] memo) {

        if (n==0 || n==1)
            return 1;
        if (memo[n] > 0) {
            return memo[n];
        }
        memo[n] = climbStairs(n-1,memo) + climbStairs(n-2,memo);
        return memo[n];
    }
}