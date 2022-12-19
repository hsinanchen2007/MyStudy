class Solution {
    public int missingNumber(int[] nums) {
        int temp = 0;
        for(int num : nums){
            if((num&temp)== num){
                temp++;
            }else{
                return temp;
            }
        }
        return temp;
    }
}