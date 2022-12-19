class Solution {
    public int[] sortArrayByParity(int[] A) {
        int[] nums = new int[A.length];
        int start = 0;
        int last = A.length-1;
        for(int i = 0;i < A.length; i++){
            if( A[i]%2 == 0 ){
            nums[start] = A[i];
            start++;
            } else{
                nums[last] = A[i];
                last--;
            }
        }
        return nums;
    }
}