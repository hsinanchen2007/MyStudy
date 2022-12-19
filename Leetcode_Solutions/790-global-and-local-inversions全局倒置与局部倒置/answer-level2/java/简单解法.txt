class Solution {
    public boolean isIdealPermutation(int[] A) {
        for (int i = 0; i < A.length; i++){
            if (i >= A[i] + 2 || i <= A[i] - 2) return false;
        }
        return true;
    }
}

