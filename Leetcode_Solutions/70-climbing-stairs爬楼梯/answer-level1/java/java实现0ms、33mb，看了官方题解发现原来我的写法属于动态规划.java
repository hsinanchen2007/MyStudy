class Solution {
    public int climbStairs(int n) {
        int[] arr = new int[n + 1];
        if (n < 3) {
            return n;
        }else {
            for (int i = 0; i < 3; i++){
                arr[i] = i;
            }
        }

        for(int i = 3; i <= n; i++) {
            arr[i] = arr[i  - 1] + arr[i - 2];
        }
        return arr[n];
    }
}