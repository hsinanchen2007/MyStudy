class Solution {
    public static boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for (int oneValue : A) {
            sum += oneValue;
        }
        if (sum % 3 == 0) {
            int threeHalf = sum / 3;
            int firstIndex = 0;
            int firstSum = 0;
            int secondIndex = A.length - 1;
            int secondSum = 0;
            for (; firstIndex < A.length; firstIndex++) {
                firstSum += A[firstIndex];
                if (firstSum == threeHalf) {
                    break;
                }
            }
            for (; secondIndex >= 0; secondIndex--) {
                secondSum += A[secondIndex];
                if (secondSum == threeHalf) {
                    break;
                }
            }
            if (secondIndex <= firstIndex+1) {
                return false;
            }
            int muddileSum = 0;
            for (int i = firstIndex + 1; i < secondIndex; i++) {
                muddileSum+=A[i];
            }
            if(firstSum==threeHalf&&muddileSum==threeHalf&&secondSum==threeHalf){
                return true;
            }else{
                return false;
            }
        } else {
            return false;
        }
    }
}