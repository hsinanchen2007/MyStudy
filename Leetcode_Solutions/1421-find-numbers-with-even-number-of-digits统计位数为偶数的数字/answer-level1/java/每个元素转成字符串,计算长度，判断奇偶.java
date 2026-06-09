class Solution {
    public int findNumbers(int[] nums) {
        int count = 0;
        for(int i=0;i<nums.length;i++){
            //每个元素转成字符串
            String num = nums[i]+"";
            //该字符串的长度
            int length = num.length();
            //判断长度为偶数，count+1
            if(length%2==0){
                count++;
            }
        }
        return count;
    }
}