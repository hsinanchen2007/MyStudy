max[i]表示以nums[i]为结尾的子数组最大乘积
min[i]表示以nums[i]为结尾的子数组的最大乘积
根据nums[i+1]的正负来计算max[i+1]和min[i+1]
public class Solution {
    public int maxProduct(int[] nums) {
        int[] max = new int[nums.length+1];
        int[] min = new int[nums.length+1];
        int result=Integer.MIN_VALUE;
        max[1]=min[1]=nums[0];
        result=max[1];
        for(int i=2;i<=nums.length;i++){
            if(nums[i-1]>=0){
                if(max[i-1]>0){
                    max[i]=max[i-1]*nums[i-1];
                    min[i]=min[i-1]*nums[i-1];
                }else {
                    max[i]=nums[i-1];
                    min[i]=min[i-1]*nums[i-1];
                }
            }else {
                if(min[i-1]>0 && max[i-1]>0){
                    max[i]=nums[i-1];
                    min[i]=max[i-1]*nums[i-1];
                }else if(max[i-1]>0 ){
                    max[i]=min[i-1]*nums[i-1];
                    min[i]=max[i-1]*nums[i-1];
                }else {
                    max[i]=min[i-1]*nums[i-1];
                    min[i]=nums[i-1];
                }
            }
            if(result<max[i]){
                result=max[i];
            }
        }
        return result;
    }
}