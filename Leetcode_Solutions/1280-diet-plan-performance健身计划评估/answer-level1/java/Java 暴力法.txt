class Solution {
    public int dietPlanPerformance(int[] calories, int k, int lower, int upper) {
        int len = calories.length;
        int sum = 0;
        int result = 0;
        for (int i = 0; i < len; i++) {
            if (i + k - 1 < len) {
                for (int j = i; j < i + k; j++) {
                    sum += calories[j];
                }
                if (sum < lower) {
                    result--;
                }
                if (sum > upper) {
                    result++;
                }
                sum = 0;
            }
        }
        return result;
    }
}