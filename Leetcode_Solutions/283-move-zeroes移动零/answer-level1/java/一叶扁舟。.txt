一叶忽略船长的小船，长度为0，沿着数组左边划到右边，每捡起一个人（数字0）,船的长度k+1，一直划到最右边。


class Solution {
    public void moveZeroes(int[] nums) {
        int k=0;
        for (int i = 0; i < nums.length; i++) {
            if(nums[i]==0){
                k++;
            }else{
                nums[i-k]=nums[i];
                nums[i]=k==0?nums[i]:0;//推开海水，没人直接走，有人“0”往前划
            }
        } 
    }
}